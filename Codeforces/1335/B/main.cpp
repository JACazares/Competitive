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
        int N, a, b;
        cin >> N >> a >> b;
        string ans = "";
        for(int i = 0; i < a; i++)
        {
            if(i < b)
                ans += (char)(i + 'a');
            else
                ans += (char)(b + 'a' - 1);
        }
        for(int i = a; i < N; i++ )
            ans += ans[i - a];
        cout << ans << "\n";
    }
    return 0;
}
