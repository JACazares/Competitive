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

const int MAXN = 505;
int N, t, p[MAXN][MAXN], idx[MAXN], latest[MAXN][MAXN];
vi ans;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
		{
			cin >> p[i][j];
			if(p[i][j] == i)
				idx[i] = j;
		}
		
	cin >> t;
	
	if(t == 1)
	{
		for(int v = 1; v <= N; v++)
			if(p[v][1] == v)
				ans.pb(v);
	}
	else
	{
		int aux = 0, to_kill;
		vi kill, safe;
		for(int i = 1; i <= N; i++)
		{
			safe.resize(N + 1, 0);
			for(int j = 1; j <= N; j++)
				safe[p[i][j]] = j;
			for(int j = 1; j <= N; j++)
				for(int k = 1; k < idx[j]; k++)
					latest[i][j] = max(latest[i][j], safe[p[j][k]]);
		}
		for(int v = 1; v <= N; v++)
		{
			for(int i = 1; i <= N; i++)
			{
				aux = 0;
				kill.clear();
				for(int j = 1; j <= N; j++)
				{
					if(p[i][j] == v)
						aux = j;
					if(!aux)
						kill.pb(p[i][j]);
				}
				to_kill = kill.size();
				for(auto j : kill)
					if(latest[i][j] >= aux)
						to_kill--;
				if(to_kill == 0)
				{
					ans.pb(v);
					break;
				}
			}
		}
	}
	cout << ans.size() << "\n"; 
	for(auto i : ans)
		cout << i << " ";
	cout << "\n";
	return 0;
}
