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
 
int pct(int x) { return __builtin_popcount((unsigned int)x); }
 
const int MAXN = 105;
int N, K, a[MAXN];

void solve()
{
	cin >> N >> K;
	vi cnt(MAXN, 0);
	bool ans = 1;
	if(N > 2*K)
		ans = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] > 2)
			ans = 0;
	}

	cout << (ans ? "YES" : "NO") << "\n";
}

int main()
{
	optimizeIO();
	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
