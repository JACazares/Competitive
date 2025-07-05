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
        int x, n, m;
        cin >> x >> n >> m;
        while(n && x/2 + 10 < x)
        {
            --n;
            x = x/2 + 10;
        }
        while(m)
        {
            --m;
            x -= 10;
        }
        
        cout << (x <= 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
