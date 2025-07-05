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
        ll N;
        cin >> N;
        for(ll i = 2; (1LL << i) - 1 <= N; i++)
            if(N % ((1LL << i) - 1) == 0)
            {
                cout << N / ((1LL << i) - 1) << "\n";
                break;
            }
    }
    return 0;
}
