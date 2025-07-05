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
    int N;
    string S;
    cin >> N;
    cin >> S;
    vi open, close;
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] == '(')
            open.push_back(i + 1);
        else if(S[i] == ')')
        {
            if(!open.empty())
                open.pop_back();
            else
                close.push_back(i + 1);
        }
    }
    
    if(open.size() != close.size())
    {
        cout << "0\n";
        cout << "1 1\n";
        return 0;
    }
    int ans = 0, p = 1, s = 1, l = 0, r = N + 1;
    if(close.size() >= 1 )
    {
        swap(S[close[close.size() - 1] - 1], S[open[0] - 1]);
        p = close[close.size() - 1];
        s = open[0];
        if(close.size() >= 2)
        {
            ans = 1;
            l = close[close.size() - 2];
            r = open[1];
        }
    }

    int cnt = 0;
    for(int i = l + 1; i < r; i++)
    {
        if(S[i - 1] == '(')
            cnt++;
        else
            cnt--;
        if(cnt == 0)
            ans++;
    }
    cout << ans << "\n";
    cout << p << " " << s << "\n";
    return 0;
}
