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

const int MAXN = (int)2e5 + 5;
int N;
ll a[MAXN], l[MAXN], r[MAXN], maxL[MAXN], maxR[MAXN];

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	
	for(int i = 1; i <= N; i++)
	{
		ll free = l[i - 1] - a[i - 1];
		l[i] = max(a[i] + free, l[i - 1] + 1);
	}
	for(int i = 1; i <= N; i++)
	{
		l[i] -= a[i];
		maxL[i] = max(maxL[i - 1], l[i]);
	}
	
	for(int i = N; i >= 1; i--)
	{
		ll free = r[i + 1] - a[i + 1];
		r[i] = max(a[i] + free, r[i + 1] + 1);
	}
	for(int i = N; i >= 1; i--)
	{
		r[i] -= a[i];
		maxR[i] = max(maxR[i + 1], r[i]);
	}
	
	ll ans = maxL[N];
	for(int i = 1; i < N; i++)
		if(l[i] + a[i] != r[i + 1] + a[i + 1])
			ans = min(ans, max(maxL[i], maxR[i + 1]));
	cout << ans << "\n";
	return 0;
}
