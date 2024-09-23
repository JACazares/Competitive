#include <iostream>

using namespace std;

void solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if(b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1)
        cout << "Y\n";
    else
        cout << "N\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}