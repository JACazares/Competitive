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
        
        ll DP[N], pos = 0, neg = 0, szPos = 0, szNeg = 0, ans = -(1LL << 60LL);
        for(int i = 0; i < N; i++)
        {
            if(a[i] > 0)
            {
                DP[i] = neg + a[i];
                if(szNeg + 1 > szPos)
                {
                    szPos = szNeg + 1;
                    pos = DP[i];
                    ans = DP[i];
                }
                pos = max(pos, DP[i]);
            }
            else
            {
                DP[i] = pos + a[i];
                if(szPos + 1 > szNeg)
                {
                    szNeg = szPos + 1;
                    neg = DP[i];
                    ans = DP[i];
                }
                neg = max(neg, DP[i]);
            }
            ans = max(ans, DP[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
