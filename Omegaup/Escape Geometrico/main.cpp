#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 105;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

struct Cell
{
	int x, y, d;
	
	bool operator <(const Cell &c) const
	{
		if(d == _c.d)
		{
			if(x == c.x)
				return y < c.y;
			return x < c.x
		}
		return d < _c.d;
	}
};

int N, M;
char a[MAXN][MAXN];

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			cin >> a[i][j];
	
	priority_queue<Cell> search_queue;
	search_queue.insert({0, 0, 0});
	while(!search_queue.empty())
	{
		Cell current = search_queue.top();
		search_queue.pop();
		
		for(int n = 0; n < 4; n++)
		{
			int new_x = x + dx[n];
			int new_y = y + dy[n];
			
			if(new_x < 0 || new_y < 
			
			int new_d;
		}
	}
	return 0;
}
