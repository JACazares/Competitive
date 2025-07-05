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
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        b = min(b, 2*a);
        if(x > y)
            swap(x, y);
        cout << x*b + (y-x)*a << "\n";
    }
    return 0;
}
