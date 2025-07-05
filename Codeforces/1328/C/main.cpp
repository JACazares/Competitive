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
        int n, fst = 1;
        string x, a = "", b = "";
        cin >> n >> x;
        for(int i = 0; i < n; i++)
        {
            if(x[i] == '2')
            {
                if(fst)
                {
                    a += "1";
                    b += "1";
                }
                else
                {
                    a += "0";
                    b += "2";
                }
            }
            else if(x[i] == '1')
            {
                if(fst)
                {
                    a += "1";
                    b += "0";
                    fst = 0;
                }
                else
                {
                    a += "0";
                    b += "1";
                }
            }
            else if(x[i] == '0')
            {
                a += "0";
                b += "0";
            }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
