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

const int MAXN = (int)2e3 + 5;
const ll MOD = (ll)1e9 + 7LL;
int N, K;
ll comb[MAXN][MAXN], DP[MAXN][MAXN];
string s;
map<string, int> MP;
vi a;

int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> s;
		sort(all(s));
		MP[s]++;
	}
	
	for(int i = 1; i <= N; i++)
	{
		comb[i][0] = 1;
		comb[i][i] = 1;
		for(int j = 1; j < i; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}
	
	for(auto i : MP)
		a.pb(i.second);
		
	DP[sz(a)][0] = 1;
	for(int i = sz(a) - 1; i >= 0; i--)
		for(int k = 0; k <= K; k++)
			for(int l = 0; l <= a[i]; l++)
				if(k >= l*(l - 1)/2)
				{
					DP[i][k] += (DP[i + 1][k - l*(l - 1)/2] * comb[a[i]][l]) % MOD;
					DP[i][k] %= MOD;
				}
	
	cout << DP[0][K] << "\n";
	return 0;
}
