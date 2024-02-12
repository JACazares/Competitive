#include "fish.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 305, MAXL = 10;
ll a[MAXN][MAXN], sum[MAXN][MAXL + 5], DP[MAXN][MAXL + 5][MAXL + 5];

ll max_weights(int N, int M, vi X, vi Y, vi W)
{
	if(N <= 300)
	{
		for(int i = 0; i < M; i++)
			a[X[i]][Y[i]] = W[i];
			
		for(int i = 0; i < N; i++)
			for(int j = 0; j < MAXL; j++)
				sum[i][j+1] = sum[i][j] + a[i][j];
				
		for(int i = N - 1; i >= 0; i--)
		{
			for(int pre = 0; pre < MAXL; pre++)
			{
				for(int me = 0; me < MAXL; me++)
				{
					for(int nxt = 0; nxt < MAXL; nxt++)
					{
						if(i == N - 1 && nxt > 0)
							break;
						DP[i][pre][me] = max(DP[i][pre][me],
											 DP[i+1][me][nxt] +
												max(sum[i][max(pre, nxt)] - sum[i][me], 0LL));
					}
					// cerr << i << ", " << pre << ", " << me << ": " << DP[i][pre][me] << "\n";
				}
			}
		}
		
		ll ans = 0;
		for(int i = 0; i < MAXL; i++)
			ans = max(ans, DP[0][0][i]);
		return ans;
	}
	return 0;
}
