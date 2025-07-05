#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

struct Cell
{
	int x, y, k, dist;
	
	Cell(int _x, int _y, int _k, int d) : x(_x), y(_y), k(_k), dist(d) {};
};

void solve()
{
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<vector<int>> a(N, vector<int>(M, 0));
	
	vector<vector<vector<int>>> vis(N, vector<vector<int>>(M, vector<int>(K + 1, 0)));
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> a[i][j];
	
	queue<Cell> search_queue;
	
	int ans = -1;
	search_queue.push({0, 0, 0, 0});
	vis[0][0][0] = 1;
	while(!search_queue.empty())
	{
		Cell current = search_queue.front();
		search_queue.pop();
		
		int x = current.x;
		int y = current.y;
		int k = current.k;
		int dist = current.dist;
		
		if(x == N - 1 && y == M - 1)
		{
			if(ans == -1)
				ans = dist;
			ans = min(ans, dist);
			
			continue;
		}
		
		for(int n = 0; n < 4; n++)
		{
			int new_x = x + dx[n];
			int new_y = y + dy[n];
			
			if(new_x < 0 || N <= new_x || new_y < 0 || M <= new_y)
				continue;
			
			int new_k;
			
			if(a[new_x][new_y] == 1)
				new_k = k + 1;
			else
				new_k = 0;
			
			if(new_k > K)
				continue;
			
			if(vis[new_x][new_y][new_k])
				continue;
			
			search_queue.push({new_x, new_y, new_k, dist+1});
			vis[new_x][new_y][new_k] = 1;
		}
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
