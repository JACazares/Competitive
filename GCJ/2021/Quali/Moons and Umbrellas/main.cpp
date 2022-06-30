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

const int MAXN = (int)1e3 + 5;
int N, X, Y, DP[MAXN][2];
string S;

void solve()
{
	cin >> X >> Y >> S;
	N = S.length();
	DP[N][0] = 0;
	DP[N][1] = 0;
	for(int i = N - 1; i >= 0; i--)
	{
		if(S[i] == 'C')
		{
			DP[i][0] = DP[i + 1][0];
			DP[i][1] = DP[i + 1][0] + Y;
		}
		else if(S[i] == 'J')
		{
			DP[i][0] = DP[i + 1][1] + X;
			DP[i][1] = DP[i + 1][1];
		}
		else
		{
			DP[i][0] = min(DP[i + 1][0], DP[i + 1][1] + X);
			DP[i][1] = min(DP[i + 1][0] + Y, DP[i + 1][1]);
		}
	}
	
	int ans = 0;
	if(S[0] == 'C')
		ans = DP[1][0];
	else if(S[0] == 'J')
		ans = DP[1][1];
	else
		ans = min(DP[1][0], DP[1][1]);
	
	cout << ans << "\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
