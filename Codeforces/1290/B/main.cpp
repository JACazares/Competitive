#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
int N, Q, pre[MAXN][26];
string S;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    N = S.length();
    S = " " + S;
    for(int i = N; i >= 1; i--)
    {
        for(int j = 0; j < 26; j++)
            pre[i][j] = pre[i + 1][j];
        pre[i][S[i] - 'a'] = i;
    }
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        if(l == r)
            cout << "Yes\n";
        else
        {
            if(S[l] != S[r])
                cout << "Yes\n";
            else
            {
                int letter = 0;
                for(int j = 0; j < 26; j++)
                    if(l <= pre[l][j] && pre[l][j] <= r)
                        ++letter;
                if(letter >= 3)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }
    return 0;
}
