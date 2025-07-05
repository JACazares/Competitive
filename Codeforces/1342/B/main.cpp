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
        string t;
        cin >> t;
        int a0 = 0, a1 = 0;
        for(auto i : t)
        {
            if(i == '0')
                a0++;
            else if(i == '1')
                a1++;
        }
        if(a0 == 0 || a1 == 0)
            cout << t << "\n";
        else
        {
            for(int i = 0; i < t.length(); i++)
                cout << "10";
            cout << "\n";
        }
    }
    return 0;
}
