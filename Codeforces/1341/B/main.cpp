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
        int N, k;
        cin >> N >> k;
        int a[N + 5];
        for(int i = 1; i <= N; i++)
            cin >> a[i];
        vi peak(N + 5, 0);
        for(int i = 2; i <= N - 1; i++)
        {
            peak[i] = peak[i - 1];
            if(a[i] > a[i - 1] && a[i] > a[i + 1])
                peak[i]++;
        }
        
        int ans1 = 1, ans2 = 1;
        for(int i = k; i <= N; i++)
        {
            if(peak[i - 1] - peak[i - k + 1] + 1 > ans1)
            {
                ans1 = peak[i - 1] - peak[i - k + 1] + 1;
                ans2 = i - k + 1;
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
