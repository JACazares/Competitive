#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 1005;
int N, M, Q, node = 0;
ll ans[MAXN];
bool vis[MAXN];
vpl Graph[MAXN];
priority_queue<pll> PQ;
map<string, int> MP;

void dijkstra(int start)
{
	for(int i = 0; i <= node; i++)
	{
		vis[i] = 0;
		ans[i] = 0;
	}
	
	PQ.push({0, start});
	while(!PQ.empty())
	{
		pll aux = PQ.top();
		PQ.pop();
		if(vis[aux.second])
			continue;
			
		vis[aux.second] = 1;
		ans[aux.second] = -aux.first;
		
		for(auto i : Graph[aux.second])
			if(!vis[i.first])
				PQ.push({aux.first - i.second, i.first});
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++) 
	{
		string _u, _v;
		ll c;
		cin >> _u >> _v >> c;
		int u = MP[_u];
		int v = MP[_v];
		if(u == 0)
		{
			node++;
			MP[_u] = node;
			u = node;
		}
		if(v == 0)
		{
			node++;
			MP[_v] = node;
			v = node;
		}
		
		Graph[u].pb({v, c});
	}
	
	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		string _u, _v;
		cin >> _u >> _v;
		int u = MP[_u];
		int v = MP[_v];
		
		dijkstra(u);
		
		if(!vis[v])
			cout << "Roger\n";
		else
			cout << ans[v] << "\n";
	}
	return 0;
}
