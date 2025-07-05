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
        ll X;
        cin >> N >> X;
        int a[N];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        sort(a, a + N, greater<int>());
        int ans = 0;
        ll sum = 0;
        for(int i = 0; i < N; i++)
        {
            if(sum + a[i] < X*(i + 1))
                break;
            sum += a[i];
            ans = i + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
