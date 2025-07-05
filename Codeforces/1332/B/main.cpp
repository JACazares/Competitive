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
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int T;
	cin >> T;
	while(T--)
    {
        int N;
        cin >> N;
        vi a(N), color(N, 0), used(11, 0);
        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
            for ( int k = 0; k < 11; k++ )
                if ( a[i] % primes[k] == 0 )
                {
                    used[k] = 1;
                    color[i] = k;
                    break;
                }
        }
        int c = 0;
        vi MP(11, 0);
        for(int i = 0; i < 11; i++)
            if(used[i])
                MP[i] = ++c;
        cout << c << "\n";
        for(int i = 0; i < N; i++)
            cout << MP[color[i]] << " ";
        cout << "\n";
    }
	return 0;
}

//2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
