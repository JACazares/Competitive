#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2005;

int N, M, deg[MAXN][MAXN], vis[MAXN][MAXN], aux, ans;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char a[MAXN][MAXN];
char c[4][2] = {{'v', '^'}, {'>', '<'}, {'<', '>'}, {'^', 'v'}};
queue < pii > Q;

int check ( int i, int j )
{
	if ( a[i][j] == '*' )
		return 0;

	int ret = 0;
	for ( int k = 0; k < 4; k++ )
		if ( a[i + dx[k]][j + dy[k]] == '.' )
			ret++;
	return ret;
}

int main ()
{
	cin >> N >> M;
	
	for ( int i = 0; i <= N + 1; i++ )
		a[i][0] = '*', a[i][M + 1] = '*';
	for ( int i = 0; i <= M + 1; i++ )
		a[0][i] = '*', a[N + 1][i] = '*';
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= M; j++ )
			cin >> a[i][j];

	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= M; j++ )
			if ( a[i][j] == '.' )
			{
				ans--;
				if ( check ( i, j ) == 1 )
					Q.push ( {i, j} );
			}
	
	while ( !Q.empty() )
	{
		auto tmp = Q.front();
		Q.pop();
		
		vis[tmp.first][tmp.second] = 1;
		for ( int i = 0; i < 4; i++ )
		{
			if ( a[tmp.first + dx[i]][tmp.second + dy[i]] == '.' )
			{
				a[tmp.first][tmp.second] = c[i][0];
				a[tmp.first + dx[i]][tmp.second + dy[i]] = c[i][1];
				vis[tmp.first + dx[i]][tmp.second + dy[i]] = 1;
				
				for ( int j = 0; j < 4; j++ )
					if ( check ( tmp.first + dx[i] + dx[j], tmp.second + dy[i] + dy[j] ) == 1
					&& !vis[tmp.first + dx[i] + dx[j]][tmp.second + dy[i] + dy[j]] )
						Q.push ( {tmp.first + dx[i] + dx[j], tmp.second + dy[i] + dy[j]} ),
						vis[tmp.first + dx[i] + dx[j]][tmp.second + dy[i] + dy[j]] = 1;
			}
		}
	}
	
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= M; j++ )
			if ( a[i][j] != '*' && a[i][j] != '.' )
				ans++;
	
	if ( ans == 0 )
	{
		for ( int i = 1; i <= N; i++ )
		{
			for ( int j = 1; j <= M; j++ )
				cout << a[i][j];
			cout << "\n";
		}
	}
	else
		cout << "Not unique\n";
	return 0;
}
