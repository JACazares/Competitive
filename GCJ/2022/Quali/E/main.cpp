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

random_device rd;
mt19937 gen(rd());

void solve()
{
	int N, K;
	cin >> N >> K;
	uniform_int_distribution<> rand_N(1, N);
	
	int a, b;
	cin >> a >> b;
	
	ll ans = 0, avg = 0, cnt = 0;
	vi vis(N + 1, 0);
	if(N <= K)
	{
		for(int i = 1; i <= N; i++)
		{
			cout << "T " << i << "\n";
			cin >> a >> b;
			ans += b;
		}
		cout << "E " << ans/2 << "\n";
	}
	else
	{
		ans += b;
		vis[a] = 1;
		cnt++;
		for(int i = 0; i < K/2; i++)
		{
			cout << "T " << rand_N(rd) << "\n";
			cin >> a >> b;
			if(!vis[a])
			{
				ans += b;
				cnt++;
			}
			vis[a] = 1;
			avg += b;
			
			cout << "W\n";
			cin >> a >> b;
			if(!vis[a])
			{
				ans += b;
				cnt++;
			}
			vis[a] = 1;
		}
		cout << "E " << ((N-cnt)*avg)/(K) + ans/2 << "\n";
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
