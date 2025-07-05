#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    ll N;
    cin >> N;
    vl a(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll hor = 0, ver = 0;
    for(int i = 0; i < N; i++ )
    {
        if ( i >= N / 2 )
            hor += a[i];
        else
            ver += a[i];
    }
    cout << hor*hor + ver*ver << "\n";
    return 0;
}
