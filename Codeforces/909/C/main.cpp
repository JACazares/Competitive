#include <iostream>
#define MAXN 5005
#define MOD 1000000007
using namespace std;
typedef long long int lld;
lld N, dp[MAXN][MAXN];
char a[MAXN];

int main () {
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= N; j++)
			dp[i][j] = 0;
	//cout << solve(0, 0)%MOD << "\n";
	for(int i = N - 1; i >= 0; i--) {
		for(int t = N - 1; t >= 0; t--) {
			if(i == N - 1)
				dp[i][t] = 1;
			else {
				if(a[i] == 'f')
					dp[i][t] = (dp[i+1][t+1])%MOD;
				else {
					if(t == N - 1)
						for(int k = 0; k <= t; k++) {
							dp[i][t]+= (dp[i + 1][k]%MOD);
							dp[i][t]%= MOD;
						}
					else
						dp[i][t] = (dp[i][t + 1] - dp[i + 1][t + 1] + MOD)%MOD;
				}
			}
		}
	}
	cout << dp[0][0] << "\n";
	return 0;
}
