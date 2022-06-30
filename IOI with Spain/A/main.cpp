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

const int MAXN = 1005;
int a[MAXN][MAXN][3], d[3][3] = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};

void solve()
{
	int r, c;
	cin >> r >> c;
	
	for(int i = 0; i < r; i++)
	{
		int aux = i%3;
		for(int j = 0; j < c; j++)
		{
			for(int k = 0; k < 3; k++)
				a[i][j][k] = d[aux][k];
			
			aux++;
			aux %= 3;
		}
	}
	for(int k = 0; k < 3; k++)
	{
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
				cout << (a[i][j][k] ? '#' : '.');
			cout << "\n";
		}
		cout << "-\n";
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
