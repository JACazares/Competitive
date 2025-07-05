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
        int a[N];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        vi vis(N, 0);
        int cnt = 1, ans = 1;
        for(int i = N - 1; i >= 0; i--)
        {
            if(a[i] == cnt)
            {
                for(int j = i; j < N; j++)
                {
                    if(vis[j])
                        continue;
                    vis[j] = 1;
                    if(a[j] != cnt)
                        ans = 0;
                    ++cnt;
                }
            }
        }
        cout << (ans ? "Yes" : "No") << "\n";
    }
    return 0;
}
