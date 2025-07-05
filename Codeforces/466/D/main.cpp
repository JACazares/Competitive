#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main ()
{
    const int MOD = 1e9 + 7;
    int N, H;
    cin >> N >> H;
    vl a ( N );
    for ( int i = 0; i < N; i++ )
        cin >> a[i];
    
    vector<vl> DP ( N + 5, vl (H + 5, 0) );
    DP[N][0] = 1;
    for ( int i = N - 1; i >= 0; i-- )
    {
        for ( int j = max ( 0, H - a[i] - 1 ); j < max ( 0, H - a[i] + 1 ); j++ )
        {
            if ( a[i] + j == H )
            {
                //close a group
                if ( j > 0 )
                    DP[i][j] += (DP[i + 1][j - 1] * j) % MOD;
                DP[i][j] %= MOD;
                //exist
                DP[i][j] += DP[i + 1][j];
                DP[i][j] %= MOD;
            }
            else if ( a[i] + j == H - 1 )
            {
                //open a group
                DP[i][j] += DP[i + 1][j + 1];
                DP[i][j] %= MOD;
                //open and close;
                DP[i][j] += DP[i + 1][j];
                DP[i][j] %= MOD;
                //close and open
                DP[i][j] += DP[i+1][j] *j % MOD;
                DP[i][j] %= MOD;
            }
            else 
            {
                DP[i][j] = 0;
            }
            DP[i][j] %= MOD;
        }
    }
    cout << DP[0][0] << "\n";
	return 0;
}
