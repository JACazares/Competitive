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
        ll N, K;
        cin >> N >> K;
        cout << N*((K - 1)/(N - 1)) + (K % (N - 1) ? K % (N - 1) : N - 1) << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

