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
	int R, C;
	cin >> R >> C;
	cout << "Case #" << t << ":\n";
	
	cout << "..";
	for(int j = 1; j < C; j++)
		cout << "+-";
	cout << "+\n";
	cout << "..";
	for(int j = 1; j < C; j++)
		cout << "|.";
	cout << "|\n";
	
	for(int i = 1; i < R; i++)
	{
		for(int j = 0; j < C; j++)
			cout << "+-";
		cout << "+\n";
		for(int j = 0; j < C; j++)
			cout << "|.";
		cout << "|\n";
	}
	for(int j = 0; j < C; j++)
		cout << "+-";
	cout << "+\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
		solve(i);
	return 0;
}
