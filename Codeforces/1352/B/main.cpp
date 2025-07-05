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
        int N, K;
        cin >> N >> K;
        if(N%2 == 1 && K%2 == 0)
            cout << "NO\n";
        else if(N%2 == 1 && K%2 == 1)
        {
            if(K <= N)
            {
                cout << "YES\n";
                for(int i = 0; i < K - 1; i++)
                    cout << "1 ";
                cout << N - K + 1 << "\n";
            }
            else
                cout << "NO\n";
        }
        else if(N%2 == 0 && K%2 == 0)
        {
            if(K <= N)
            {
                cout << "YES\n";
                for(int i = 0; i < K - 1; i++)
                    cout << "1 ";
                cout << N - K + 1 << "\n";
            }
            else
                cout << "NO\n";
        }
        else if(N%2 == 0 && K%2 == 1)
        {
            if(2*K <= N)
            {
                cout << "YES\n";
                for(int i = 0; i < K - 1; i++)
                    cout << "2 ";
                cout << N - 2*K + 2 << "\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

