#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        int a[N];
        vi vis(N + 5, 0), dist;
        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
            if(!vis[a[i]])
                dist.push_back(a[i]);
            vis[a[i]] = 1;
        }
        if(dist.size() > K)
            cout << "-1\n";
        else
        {
            cout << N * K << "\n";
            for(int i = 0; i < N; i++)
            {
                for(auto j : dist)
                    cout << j << " ";
                for(int j = dist.size(); j < K; j++)
                    cout << dist[dist.size() - 1] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
