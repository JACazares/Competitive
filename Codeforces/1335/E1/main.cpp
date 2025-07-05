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
        int a[N + 5];
        vector<vi> pre(N + 1, vi(205, 0));
        for(int i = 1; i <= N; i++)
        {
            cin >> a[i];
            for(int j = 1; j <= 200; j++)
                pre[i][j] = pre[i - 1][j];
            pre[i][a[i]]++;
        }
        
        vi rpnt(205, N + 1), cnt(205, 0);
        int ans = 0;
        for(int i = 1; i <= N; i++)
        {
            cnt[a[i]]++;
            while(rpnt[a[i]] > 0 && a[rpnt[a[i]] - 1] != a[i])
                rpnt[a[i]]--;
            rpnt[a[i]]--;
            if(rpnt[a[i]] < i)
                continue;
            else if(rpnt[a[i]] == i)
            {
                ans = max(ans, 2*cnt[a[i]] - 1);
                continue;
            }

            int aux = 0;
            for(int j = 1; j <= 200; j++)
                aux = max(aux, pre[rpnt[a[i]] - 1][j] - pre[i][j] + 2*cnt[a[i]]);
            ans = max(ans, aux);
        }
        cout << ans << "\n";
    }
    return 0;
}
