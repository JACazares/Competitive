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

int N, W, c, w;
ld ans = 0;

int main()
{
	cin >> N >> W;
	for(int i = 0; i < N; i++)
	{
		cin >> c >> w;
		ans = max(ans, (ld)c*W/w);
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << ans << "\n";
	return 0;
}
