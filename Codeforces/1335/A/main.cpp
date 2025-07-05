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
        if(N&1)
            cout << N/2;
        else
            cout << N/2 - 1;
        cout << "\n";
    }
    return 0;
}
