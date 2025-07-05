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
        int lpnt = 0, rpnt = N - 1, turn = 0;
        ll lans = 0, rans = 0, ans = 0, sum = 0, lastsum = 0;
        while(lpnt <= rpnt)
        {
            ans++;
            if(turn == 0)
            {
                while(lpnt <= rpnt && sum <= lastsum)
                {
                    sum += a[lpnt];
                    lans += a[lpnt];
                    lpnt++;
                }
            }
            else
            {
                while(lpnt <= rpnt && sum <= lastsum)
                {
                    sum += a[rpnt];
                    rans += a[rpnt];
                    rpnt--;
                }
            }
            
            lastsum = sum;
            sum = 0;
            turn ^= 1;
        }
        cout << ans << " " << lans << " " << rans << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

