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

const int MAX = 1e6;

void solve(int t)
{
	int A[4][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			cin >> A[j][i];
		
	int a[4];
	for(int j = 0; j < 4; j++)
	{
		a[j] = A[j][0];
		for(int i = 0; i < 3; i++)
			a[j] = min(a[j], A[j][i]);
	}
	
	cout << "Case #" << t << ": ";
	if(a[0] + a[1] + a[2] + a[3] < 1e6)
		cout << "IMPOSSIBLE\n";
	else
	{
		int sum = 0;
		for(int i = 0; i < 4; i++)
		{
			if(sum + a[i] <= MAX)
			{
				cout << a[i] << " ";
				sum += a[i];
			}
			else if(sum < MAX)
			{
				cout << MAX - sum << " ";
				sum = MAX;
			}
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
		solve(t);
	return 0;
}
