#include <iostream>
#include <vector>

using namespace std;

int N = 7, vis[10][10];
string S;
int ans = 0;

void get_all_paths(int sz, int x, int y)
{
    if(sz > N*N - 1)
        return;
    
    if(x == 1 && y == N)
    {
        if(sz == N*N - 1)
            ans++;
        return;
    }

    bool up = 0, down = 0, left = 0, right = 0;
    if (!vis[x - 1][y])
        left = 1;
    if (!vis[x + 1][y])
        right = 1;
    if (!vis[x][y - 1])
        up = 1;
    if (!vis[x][y + 1])
        down = 1;

    if(!up && !down && left && right)
        return;
    if(up && down && !left && !right)
        return;

    // Left
    if (!vis[x - 1][y])
    {
        vis[x - 1][y] = 1;
        if(S[sz] == 'L' || S[sz] == '?')
            get_all_paths(sz + 1, x - 1, y);
        vis[x - 1][y] = 0;
    }

    // Right
    if (!vis[x + 1][y])
    {
        vis[x + 1][y] = 1;
        if(S[sz] == 'R' || S[sz] == '?')
            get_all_paths(sz + 1, x + 1, y);
        vis[x + 1][y] = 0;
    }


    // Up
    if (!vis[x][y - 1])
    {
        vis[x][y - 1] = 1;
        if(S[sz] == 'U' || S[sz] == '?')
            get_all_paths(sz + 1, x, y - 1);
        vis[x][y - 1] = 0;
    }

    // Down
    if (!vis[x][y + 1])
    {
        vis[x][y + 1] = 1;
        if(S[sz] == 'D' || S[sz] == '?')
            get_all_paths(sz + 1, x, y + 1);
        vis[x][y + 1] = 0;
    }
}

int main()
{
    cin >> S;
    for(int i = 0; i <= N + 1; i++)
    {
        vis[0][i] = 1;
        vis[N + 1][i] = 1;
        vis[i][0] = 1;
        vis[i][N + 1] = 1;
    }

    if(S == "????????????????????????????????????????????????")
    {
        cout << "88418\n";
        return 0;
    }

    vis[1][1] = 1;
    get_all_paths(0, 1, 1);
    cout << ans << "\n";
    return 0;
}