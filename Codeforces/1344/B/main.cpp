#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1005;
int N, M, vis[MAXN][MAXN];
char a[MAXN][MAXN];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool valid(int i, int j)
{
    if(i < 0 || N <= i)
        return 0;
    if(j < 0 || M <= j)
        return 0;
    if(a[i][j] == '.')
        return 0;
    if(vis[i][j])
        return 0;
    return 1;
}

void dfs(int i, int j)
{
    if(!valid(i, j))
        return;
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++)
        if(valid(i + dx[k], j + dy[k]))
            dfs(i + dx[k], j + dy[k]);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> a[i][j];
    
    ll ans = 0, rows = 0, cols = 0;
    for(int i = 0; i < N; i++)
    {
        bool on = 0, off = 0;
        for(int j = 0; j < M; j++)
        {
            if(on && off && a[i][j] == '#')
                ans = -1;
            else if(on && a[i][j] == '.')
                off = 1;
            else if(a[i][j] == '#')
                on = 1;
        }
        if(on)
            rows++;
    }
    for(int j = 0; j < M; j++)
    {
        bool on = 0, off = 0;
        for(int i = 0; i < N; i++)
        {
            if(on && off && a[i][j] == '#')
                ans = -1;
            else if(on && a[i][j] == '.')
                off = 1;
            else if(a[i][j] == '#')
                on = 1;
        }
        if(on)
            cols++;
    }
    
    if((rows == N && cols != M) || (rows != N && cols == M))
        ans = -1;

    if(ans != -1)
    {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(a[i][j] == '#' && !vis[i][j])
                {
                    ans++;
                    dfs(i, j);
                }
    }
    cout << ans << "\n";
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
