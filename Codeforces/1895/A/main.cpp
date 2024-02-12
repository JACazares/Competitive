#include <iostream>

using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if(x < y)
        x = min(x + k, y);
    
    cout << y + abs(y - x) << "\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}