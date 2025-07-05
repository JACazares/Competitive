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
        char a[9][9];
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == '2')
                    a[i][j] = '1';
            }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                cout << a[i][j];
            cout << "\n";
        }
    }
    return 0;
}
