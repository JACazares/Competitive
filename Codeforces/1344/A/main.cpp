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
        int N;
        cin >> N;
        int a[N], ans = 1;
        vi vis(N, 0);
        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
            if(vis[((i + a[i])%N + N) % N])
                ans = 0;
            vis[((i + a[i])%N + N) % N]++;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
