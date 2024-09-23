#include <iostream>
#include <vector>

using namespace std;

int N = 7, vis[10][10];
string S;
vector<string> paths;

void get_all_paths(string path, int x, int y)
{
    if(path.size() > N*N - 1)
        return;
    
    if(x == 1 && y == N)
    {
        if(path.size() == N*N - 1)
            paths.push_back(path);
        return;
    }

    bool up = 0, down = 0, left = 0, right = 0;
    if (!vis[x - 1][y])
        up = 1;
    if (!vis[x + 1][y])
        down = 1;
    if (!vis[x][y - 1])
        left = 1;
    if (!vis[x][y + 1])
        right = 1;

    if(!up && !down && left && right)
        return;
    if(up && down && !left && !right)
        return;

    // Up
    if (!vis[x - 1][y])
    {
        vis[x - 1][y] = 1;
        get_all_paths(path + "U", x - 1, y);
        vis[x - 1][y] = 0;
    }

    // Down
    if (!vis[x + 1][y])
    {
        vis[x + 1][y] = 1;
        get_all_paths(path + "D", x + 1, y);
        vis[x + 1][y] = 0;
    }


    // Left
    if (!vis[x][y - 1])
    {
        vis[x][y - 1] = 1;
        get_all_paths(path + "L", x, y - 1);
        vis[x][y - 1] = 0;
    }

    // Right
    if (!vis[x][y + 1])
    {
        vis[x][y + 1] = 1;
        get_all_paths(path + "R", x, y + 1);
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

    vis[1][1] = 1;
    get_all_paths("", 1, 1);
    cout << paths.size() << "\n";
    return 0;
}