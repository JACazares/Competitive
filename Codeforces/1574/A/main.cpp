#include <iostream>

using namespace std;

int N, sz, cnt;

void printall(int open = 0, string s = "")
{
    if(cnt == N)
        return;
    if(s.length() == sz)
    {
        if(open == 0)
        {
            cout << s << "\n";
            cnt++;
        }
        return;
    }
    if(open > 0)
        printall(open - 1, s + ")");
    printall(open + 1, s + "(");
}

void solve()
{
    cin >> N;
    sz = N * 2;
    cnt = 0;
    printall();
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;   
}
