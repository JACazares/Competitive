#include <iostream>

using namespace std;

const int MAXN = 305;
int N, M, w[MAXN], l[MAXN], r[MAXN];
int DP[MAXN][MAXN];

int main()
{
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);

	cin >> N >> M;
	for(int i = 0; i < M; i++)
		cin >> w[i] >> l[i] >> r[i];
	
	for(int sz = 0; sz < N; sz++)
	{
	
		for(int x = 1; x <= N; x++)
		{
			int y = x + sz;
			if(y > N)
				break;
				
			for(int i = 0; i < M; i++)
			{
				if((l[i] <= x && x <= r[i]) || (l[i] <= y && y <= r[i]))
					DP[x][y] = max(DP[x][y], DP[x][l[i] - 1] + DP[r[i] + 1][y] + w[i]);
			}
		}
	}
	cout << DP[1][N] << "\n";
	return 0;
}
