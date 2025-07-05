#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int check(string S)
{
    vi open, close;
    close.push_back(0);
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
    open.push_back(S.length() + 1);
    
    if(open.size() != close.size())
        return 0;
    int ans = 1, cnt = 0;
    if(open.size() == 1 )
        ans = 0;
    for(int i = close[close.size()-1] + 1; i < open[0]; i++)
    {
        if(S[i - 1] == '(')
            cnt++;
        else
            cnt--;
        if(cnt == 0)
            ans++;
    }
    return ans;
}

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    int N;
    string S;
    cin >> N;
    cin >> S;
    int ans = check(S), p = 1, s = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            swap(S[i], S[j]);
            int aux = check(S);
            if(aux > ans)
            {
                ans = aux;
                p = i + 1;
                s = j + 1;
            }
            swap(S[i], S[j]);
        }
    }
    cout << ans << "\n" << p << " " << s << "\n";
    return 0;
}
