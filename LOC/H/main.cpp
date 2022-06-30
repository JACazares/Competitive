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

const int MAXN = 205, MOD = (int)1e9 + 7;
int N;
ll DP[MAXN][MAXN];

int main()
{
	cin >> N;
	N /= 2;
	DP[0][0] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j <= 9*N; j++)
			for(int k = 0; k <= 9; k++)
				if(j - k >= 0)
				{
					DP[i][j] += DP[i - 1][j - k];
					DP[i][j] %= MOD;
				}
	
	
	ll ans = 0;
	for(int i = 0; i <= 9*N; i++)
	{
		ans += (DP[N][i] * DP[N][i]) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}
