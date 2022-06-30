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

const int MAXN = 105;
int N, a[MAXN];

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i < N; i++)
	{
		int idx = i;
		for(int j = i; j <= N; j++)
			if(a[j] < a[idx])
				idx = j;
		
		reverse(a + i, a + idx + 1);
		ans += idx - i + 1;
	}
	
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
