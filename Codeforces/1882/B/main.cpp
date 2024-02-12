#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
int N, M[MAXN], k[MAXN][MAXN], cnt[MAXN];

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> M[i];
		for(int j = 0; j < M[i]; j++)
			cin >> k[i][j];
	}
	
	int ans = 0;
	for(int e = 1; e <= 50; e++)
	{
		for(int i = 1; i <= 50; i++)
			cnt[i] = 0;
			
		int aux = 0, totrem = 0;
		for(int i = 0; i < N; i++)
		{
			int rem = 0;
			for(int j = 0; j < M[i]; j++)
				if(k[i][j] == e)
					rem = 1;
			
			totrem += rem;
			
			if(!rem)
				for(int j = 0; j < M[i]; j++)
					if(!cnt[k[i][j]])
					{
						aux++;
						cnt[k[i][j]] = 1;
					}
		}
		
		if(totrem > 0)
			ans = max(ans, aux);
	}
	
	cout << ans << "\n";
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
