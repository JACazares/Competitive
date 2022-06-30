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
int N, X, a[MAXN];

void solve()
{
	cin >> N >> X;
	if(X < N-1 || N*(N+1)/2 - 1 < X)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	X -= N - 1;
	a[N] = N;
	for(int i = N - 1; i >= 1; i--)
	{
		a[i] = i;
		if(X >= N - i)
		{
			reverse(a + i, a + N + 1);
			X -= (N - i);
		}
		else
		{
			reverse(a + i, a + X + i + 1);
			X = 0;
		}
	}
	
	for(int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << "\n";
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
