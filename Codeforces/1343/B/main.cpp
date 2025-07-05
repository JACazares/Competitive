#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        if(N % 4 != 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            ll sum = 0;
            for(int i = 0; i < N/2; i++)
            {
                cout << 2*i + 2 << " ";
                sum += 2*i + 2;
            }
            for(int i = 0; i < N/2 - 1; i++)
            {
                cout << 2*i + 1 << " ";
                sum -= 2*i + 1;
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
