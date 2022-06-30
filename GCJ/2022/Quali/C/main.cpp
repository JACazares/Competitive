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

void solve(int t)
{
	int N;
	cin >> N;
	vi a(N, 0);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	sort(all(a));
	int ans = 0, l = 0, aux = 0;
	for(int i = 0; i < N; i++)
	{
		while(a[i] <= (i - l))
		{
			l++;
			aux--;
		}
		aux++;
		ans = max(ans, aux);
	}
	cout << "Case #" << t << ": " << ans << "\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
		solve(i);
	return 0;
}
