#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pll>;
using vpl = vector<pll>;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = (int)1e5 + 5;
int N, c[MAXN], p[MAXN];
vi T[MAXN];

pll dfs(int node)
{
	pll result = {c[node], 0};
	ll values = 0, min_val = 0;
	
	for(auto i : T[node])
	{
		pll aux = dfs(i);
		result.second += aux.second;
		values += aux.first;
		if(min_val == 0)
			min_val = aux.first;
		min_val = min(min_val, aux.first);
	}
	
	result.second += values - min_val;
	result.first = max(result.first, min_val);
	
	return result;
}

void solve()
{
	cin >> N;
	for(int i = 0; i <= N; i++)
		T[i].clear();
		
	for(int i = 1; i <= N; i++)
		cin >> c[i];
	for(int i = 1; i <= N; i++)
	{
		cin >> p[i];
		T[p[i]].pb(i);
	}
	
	pll aux = dfs(0);
	cout << aux.first + aux.second << "\n";
}

int main()
{
	int _T;
	cin >> _T;
	for(int i = 1; i <= _T; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
