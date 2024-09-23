#include <iostream>

using namespace std;

void solve(int t)
{
    int ans = 1;
    for(int i = 0; i < 13; i++)
    {
        int a;
        cin >> a;
        if(a == 0)
            ans = 0;
    }

    cout << "Set #" << t << ": " << (ans ? "Yes" : "No") << "\n";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
        solve(t);
    return 0;
}