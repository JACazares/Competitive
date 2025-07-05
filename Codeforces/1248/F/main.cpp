#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, N, M;
vi vis[2];
vector<vi> g[2];

void dfs(int node, int side)
{
    if(vis[side][node])
        return;
    vis[side][node] = 1;
    for(auto i : g[side][node])
        dfs(i, side ^ 1);
}

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        g[0].clear();
        g[1].clear();
        g[0].resize(N + 5);
        g[1].resize(N + 5);
        vis[0].clear();
        vis[1].clear();
        vis[0].resize(N + 5);
        vis[1].resize(N + 5);
        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            g[0][a].push_back(b);
            g[1][b].push_back(a);
        }
        if(N == 1)
        {
            cout << "No\n";
            continue;
        }
        dfs ( 1, 0 );
        vi c1, c2;
        int mindeg = N;
        for(int i = 1; i <= N; i++)
        {
            if(vis[0][i])
                c1.push_back(i);
            if(vis[1][i])
                c2.push_back(i);
            mindeg = min(mindeg, (int)min(g[0][i].size(), g[1][i].size()));
        }
        
        if(max(c1.size(), c2.size()) < N)
        {
            cout << "Yes\n";
            if(c1.size() > c2.size())
            {
                cout << c1.size() << " " << N - c1.size() << "\n";
                for(auto i : c1)
                    cout << i << " ";
                cout << "\n";
                for(int i = 1; i <= N; i++)
                    if(!vis[0][i])
                        cout << i << " ";
                cout << "\n";
            }
            else
            {
                cout << N - c2.size() << " " << c2.size() << "\n";
                for(int i = 1; i <= N; i++)
                    if(!vis[1][i])
                        cout << i << " ";
                cout << "\n";
                for(auto i : c2)
                    cout << i << " ";
                cout << "\n";
            }
        }
        else if(mindeg == 1)
        {
            for(int i = 1; i <= N; i++)
            {
                if(g[0][i].size() == 1)
                {
                    cout << "Yes\n";
                    cout << "1 " << N - 1 << "\n";
                    cout << i << "\n";
                    for(int j = 1; j <= N; j++)
                        if(j != i)
                            cout << j << " ";
                    cout << "\n";
                    break;
                }
                else if(g[1][i].size() == 1)
                {
                    cout << "Yes\n";
                    cout << N - 1 << " 1\n";
                    for(int j = 1; j <= N; j++)
                        if(j != i)
                            cout << j << " ";
                    cout << i << "\n";
                    cout << "\n";
                    break;
                }
            }
        }
        else
            cout << "No\n";
    }
    return 0;
}
