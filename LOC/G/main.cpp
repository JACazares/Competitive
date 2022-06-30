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

const int MAXN = 305;
int A, B, C, DP[MAXN][MAXN][MAXN];
string X, Y, Z;

int main()
{
	cin >> A >> B >> C;
	cin >> X >> Y >> Z;
	for(int i = A - 1; i >= 0; i--)
		for(int j = B - 1; j >= 0; j--)
			for(int k = C - 1; k >= 0; k--)
			{
				DP[i&1][j][k] = max(DP[(i+1)&1][j][k], max(DP[i&1][j + 1][k], DP[i&1][j][k + 1]));
				if(X[i] == Y[j] && X[i] == Z[k])
					DP[i&1][j][k] = max(DP[i&1][j][k], DP[(i+1)&1][j + 1][k + 1] + 1);
			}
	
	cout << DP[0][0][0] << "\n";
	return 0;
}

