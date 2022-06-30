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
int N, M, DP[MAXN][MAXN];
string S, T;
pii nxt[MAXN][MAXN];

int main()
{
	cin >> N >> M;
	cin >> S >> T;
	for(int i = N - 1; i >= 0; i--)
		for(int j = M - 1; j >= 0; j--)
		{
			DP[i][j] = max(DP[i + 1][j], DP[i][j + 1]);
			if(S[i] == T[j])
				DP[i][j] = max(DP[i][j], DP[i + 1][j + 1] + 1);
			
			if(S[i] == T[j] && DP[i][j] == DP[i + 1][j + 1] + 1)
				nxt[i][j] = {1, 1};
			else if(DP[i][j] == DP[i + 1][j])
				nxt[i][j] = {1, 0};
			else if(DP[i][j] == DP[i][j + 1])
				nxt[i][j] = {0, 1};
		}
	
	int aI = 0, aJ = 0;
	cout << DP[0][0] << "\n";
	while(aI < N && aJ < M)
	{
		if(nxt[aI][aJ].first == 1 && nxt[aI][aJ].second == 1)
			cout << S[aI];
		pii aux = nxt[aI][aJ];
		aI += aux.first;
		aJ += aux.second;
	}
	cout << "\n";
	return 0;
}
