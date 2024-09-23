#include <iostream>

using namespace std;

void solve(int t)
{
    int N, K, P;
    cin >> N >> K >> P;
    int ans = (K + P) % N;
    if(ans == 0)
        ans = N;
    
    cout << "Case " << t << ": " << ans << "\n";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
        solve(t);
    return 0;
}