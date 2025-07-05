#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAXN = 200005;
 
int N, p[MAXN], sz[MAXN];
vi Graph[MAXN];
 
int pre ( int node )
{
	sz[node] = 1;
	for ( auto i : Graph[node] )
		sz[node] += pre ( i );
	return sz[node];
}
 
void dfs ( int node )
{
	for ( auto i : Graph[node] )
		if ( sz[i] % 2 == 0 )
			dfs ( i );
	cout << node << "\n";
	for ( auto i : Graph[node] )
		if ( sz[i] % 2 == 1 )
			dfs ( i );
}
 
int main ()
{
	int rootNode;
	cin >> N;
	for ( int i = 1; i <= N; i++ )
	{
		cin >> p[i];
		if ( p[i] == 0 )
			rootNode = i;
		Graph[p[i]].push_back ( i );
	}
	
	if ( N % 2 == 1 )
	{
		cout << "YES\n";
		pre ( rootNode );
		dfs ( rootNode );
	}
	else
		cout << "NO\n";
 
	return 0;
}
