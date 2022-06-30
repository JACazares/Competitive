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

const ll P = 97;
const int MAXN = 305;
ull roll[MAXN], mult[MAXN];
ll DP[MAXN][MAXN];

ull _hash(int i, int j)
{
	return roll[i] - roll[j + 1]*mult[j-i+1];
}

void solve()
{
	string S;
	cin >> S;
	int N = (int)S.length();
	if(N > 300)
	{
		cout << "1\n";
		return;
	}
	
	roll[N + 1] = 0;
	for(int i = N - 1; i >= 0; i--)
		roll[i] = roll[i+1]*P + (S[i] - 'a');
	
	for(int sz = 1; sz <= N; sz++)
		for(int i = 0; i <= N - sz; i++)
		{
			DP[i][sz] = 1;
			for(int k = 1; 2*k <= sz; k++)
				if(_hash(i, i+k-1) == _hash(i+sz-k, i+sz-1))
					DP[i][sz] = max(DP[i][sz], DP[i+k][sz-2*k] + 2);
		}
	
	cout << DP[0][N] << "\n";
	return;
}

int main()
{
	mult[0] = 1;
	for(int i = 1; i <= 300; i++)
		mult[i] = mult[i - 1] * P;
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
