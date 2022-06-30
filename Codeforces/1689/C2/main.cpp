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
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second

const int MAXN = 3e5 + 5;
vi Graph[MAXN];

int minicount(int vertex, int parent)
{
	auto children = Graph[vertex];
	if(vertex != 1)
		erase(children, parent);
	
	if(sz(children) == 0)
		return 1;
	else if(sz(children) == 1)
		return 2;
	else
	{
		int count0 = minicount(children[0], vertex);
		int count1 = minicount(children[1], vertex);
		return min(count0, count1) + 2;
	}
}

int solve()
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
		Graph[i].clear();
	for(int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	
	return N - minicount(1, 0);
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		cout << solve() << "\n";
	return 0;
}
