#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    const int MOD = 1e9 + 7;
    int N, M;
    cin >> N >> M;
    ll fib[max(N, M) + 1];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= max(N, M); i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    cout << ((2*fib[M] - 2 + 2*fib[N])%MOD + MOD)%MOD << "\n";
    return 0;
}
