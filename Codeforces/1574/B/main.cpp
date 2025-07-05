#include <bits/stdc++.h>

using namespace std;

int a[3], m;

void solve()
{
    for(int i = 0; i < 3; i++)
        cin >> a[i];
    cin >> m;
    sort(a, a + 3);
    int maxim = a[0] + a[1] + a[2] - 3;
    int minim = a[2] - (a[1] + a[0]) - 1;
    cout << (minim <= m && m <= maxim ? "YES" : "NO") << "\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
