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
        int N, a, b, c, d;
        cin >> N >> a >> b >> c >> d;
        // a - b minimum, a + b maximum, c - d minimum, c + d maximum
        if(c+d < (a-b)*N || c-d > (a+b)*N)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
