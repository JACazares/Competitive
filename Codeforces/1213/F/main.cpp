#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 200005;

int N, K, u, v, id[MAXN], low[MAXN], vis[MAXN], inStack[MAXN], cnt, scc_count = 1, SCC[MAXN], p[MAXN];
int indeg[MAXN];
char letter[MAXN], curr_letter = 'a';
vi Graph[MAXN], DAG[MAXN];
stack < int > S;
queue < int > Q;

void dfs ( int node )
{
	id[node] = cnt;
	low[node] = cnt;
	vis[node] = 1;
	inStack[node] = 1;
	S.push ( node );
	cnt++;
	
	for ( auto i : Graph[node] )
	{
		if ( !vis[i] )
		{
			dfs ( i );
			low[node] = min ( low[node], low[i] );
		}
		else if ( inStack[i] )
			low[node] = min ( low[node], id[i] );
	}
	
	if ( low[node] == id[node] )
	{
		while ( !S.empty() && S.top() != node )
			SCC[S.top()] = scc_count, inStack[S.top()] = 0, S.pop();
		SCC[S.top()] = scc_count++, inStack[S.top()] = 0, S.pop();
	}
}

int look ( int node )
{
	if ( p[node] == node )
		return node;
	return p[node] = look ( p[node] );
}

void join ( int _1, int _2 )
{
	p[look(_2)] = look(_1);
}

int main ()
{
	cin >> N >> K;
	u = -1;
	for ( int i = 0; i < N; i++ )
	{
		cin >> v;
		if ( u != -1 )
			Graph[u].push_back ( v );
		u = v;
	}
	
	u = -1;
	for ( int i = 0; i < N; i++ )
	{
		cin >> v;
		if ( u != -1 )
			Graph[u].push_back ( v );
		u = v;
	}
	
	for ( int i = 1; i <= N; i++ )
		if ( !vis[i] )
			dfs ( i );

	for ( int i = 1; i <= N; i++ )
		p[i] = i;
	for ( int i = 1; i <= N; i++ )
		for ( auto n : Graph[i] )
			if ( look ( SCC[i] ) != look ( SCC[n] ) )
				DAG[SCC[i]].push_back ( SCC[n] ), join ( SCC[i], SCC[n] ), indeg[SCC[n]]++;
	
	if ( scc_count > K )
	{
		for ( int i = 1; i < scc_count; i++ )
			if ( indeg[i] == 0 )
				Q.push ( i );

		while ( !Q.empty() )
		{
			auto aux = Q.front();
			Q.pop();
			
			letter[aux] = curr_letter;
			if ( curr_letter != 'z' )
				curr_letter++;
			
			for ( auto i : DAG[aux] )
				Q.push ( i );
		}
		
		cout << "YES\n";
		for ( int i = 1; i <= N; i++ )
			cout << letter[SCC[i]];
		cout << "\n";
	}
	else
		cout << "NO\n";
			
	return 0;
}
