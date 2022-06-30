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

const int MAXN = 105, MAXS = (int)1e4 + 5;
int N, S, w[MAXN], c[MAXN], DP[MAXN][MAXS];

int main()
{
	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> w[i] >> c[i];
	
	for(int i = N - 1; i >= 0; i--)
		for(int s = 0; s <= S; s++)
			DP[i][s] = max((s - w[i] >= 0 ? DP[i + 1][s - w[i]] + c[i] : 0), DP[i + 1][s]);
	
	cout << DP[0][S] << "\n";
	return 0;
}
