#include <iostream>

using namespace std;

const int INF = (1<<30);

void solve()
{
    int N, M;
    cin >> N >> M;
    int maxim = -INF, x = 0, y = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if(a > maxim)
            {
                maxim = a;
                x = i;
                y = j;
            }
        }
    
    cout << max(x + 1, N - x) * max(y + 1, M - y) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) 
        solve();
}
