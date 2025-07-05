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
        int n0, n1, n2;
        string ans = "";
        cin >> n0 >> n1 >> n2;
        if(n0 == 0 && n1 == 0)
        {
            ans += "1";
            while(n2--)
                ans += "1";
        }
        else if(n1 == 0 && n2 == 0)
        {
            ans += "0";
            while(n0--)
                ans += "0";
        }
        else
        {
            while(n0--)
                ans += "0";
            ans += "01";
            n1--;
            while(n1 > 1)
            {
                ans += "01";
                n1 -= 2;
            }
            while(n2--)
                ans += "1";
            if(n1 == 1)
            {
                ans += "0";
                n1--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

