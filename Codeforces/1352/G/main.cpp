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
        if(N <= 3)
            cout << "-1\n";
        else if(N == 4)
            cout << "3 1 4 2\n";
        else
        {
            for(int i = 1; i <= N; i += 2)
                cout << i << " ";
            if(N%2 == 1)
            {
                cout << N - 3 << " " << N - 1 << " ";
                for(int i = N - 5; i >= 1; i -= 2)
                    cout << i << " ";
            }
            else
            {
                cout << N - 4 << " " << N << " " << N - 2 << " ";
                for(int i = N - 6; i >= 1; i -= 2)
                    cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

