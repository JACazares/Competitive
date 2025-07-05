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
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        pii a[N];
        for(int i = 0; i < N; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + N);
        int minim = a[0].second, maxim = a[0].second;
        for(int i = 0; i < N; i++)
        {
            minim = min ( minim, a[i].second );
            maxim = max ( maxim, a[i].second );
            if(maxim - minim == i )
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
