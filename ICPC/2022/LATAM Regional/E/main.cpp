#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 3e5 + 5;
int N, M, vis[MAXN];
vi Graph[MAXN];
vector<char> ans;

int dfs(int node)
{
	vis[node] = 1;
	int ret = node;
	for(auto i : Graph[node])
		if(!vis[i])
			ret = max(ret, dfs(i));
	return ret;
}

void dfs2(int node)
{
	ans[node - 1] = 'B';
	
	vis[node] = 2;
	for(auto i : Graph[node])
		if(vis[i] != 2)
			dfs2(i);
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	
	int B = 0, maxim = 0;
	vis[N] = 2;
	for(auto i : Graph[N])
		if(!vis[i])
		{
			int aux = dfs(i);
			cerr << i << ", " << aux << "\n";
			if(maxim <= aux)
			{
				maxim = aux;
				B = i;
			}
		}
	
	ans.resize(N, 'A');
	dfs2(B);
	for(auto i : ans)
		cout << i;
	cout << "\n";
	return 0;
}
