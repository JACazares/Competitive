#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;

int T, N, M;
vi vis;
vector<vi> p, Graph;

void pre(int node)
{
    if(vis[node])
        return;
    vis[node] = 1;
    
    for(auto i : Graph[node])
    {
        p[node][0] = i;
        pre(i);
    }
    for(int k = 1; k <= 21; k++)
        p[node][k] = p[p[node][k - 1]][k - 1];
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        char a[N][M], d[N][M];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> a[i][j];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> d[i][j];
        
        Graph.clear();
        Graph.resize(N*M);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                int node = i*M + j;
                if(d[i][j] == 'U')
                    Graph[node].push_back((i - 1)*M + j);
                else if(d[i][j] == 'D')
                    Graph[node].push_back((i + 1)*M + j);
                else if(d[i][j] == 'L')
                    Graph[node].push_back(i*M + j - 1);
                else if(d[i][j] == 'R')
                    Graph[node].push_back(i*M + j + 1);
            }
        }

        vis.clear();
        p.clear();
        vis.resize(N*M);
        p.resize(N*M, vi(22, 0));
        for(int i = 0; i < N*M; i++)
            if(!vis[i])
                pre(i);

        vi black, white;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
            {
                if(a[i][j] == '0')
                    black.push_back(i*M + j);
                else
                    white.push_back(i*M + j);
            }
        
        int tot = 0, b = 0;
        vi used(N*M, 0);
        for(auto i : black)
        {
            if(!used[p[i][21]])
                tot++, b++;
            used[p[i][21]] = 1;
        }
        for(auto i : white)
        {
            if(!used[p[i][21]])
                tot++;
            used[p[i][21]] = 1;
        }
        cout << tot << " " << b << "\n";
    }
    return 0;
}
