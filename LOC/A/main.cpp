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

const int MAXN = (int)1e5 + 5, MOD = (int)1e9 + 7;
ll N, DP[MAXN], pre[MAXN];

int main()
{
	cin >> N;
	DP[0] = 1;
	DP[1] = 2;
	DP[2] = 4;
	for(int i = 3; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
		DP[i] %= MOD;
	}
	cout << DP[N] << "\n";
	return 0;
}
