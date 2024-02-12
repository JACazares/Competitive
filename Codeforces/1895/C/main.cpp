#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using vs = vector<string>;

int N, sums[10][50];
vs len[10];

int qry(string s, int a, int b)
{
    int sum = 0;
    for(int i = a; i < b; i++)
        sum += (int)(s[i] - '0');
    return sum;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        string s = to_string(x);
        len[s.length()].push_back(s);
    }

    ll ans = 0;
    for(int i = 1; i <= 5; i++)
    {
        for(auto s : len[i])
        {
            ans += 2*sums[i][qry(s, 0, i)];
            for(int j = 1; 2*j < i; j++)
            {
                if(qry(s, j, i) >= qry(s, 0, j))
                    ans += sums[i - 2*j][qry(s, j, i) - qry(s, 0, j)];

                if(qry(s, 0, i - j) >= qry(s, i - j, i))
                    ans += sums[i - 2*j][qry(s, 0, i - j) - qry(s, i - j, i)];
            }

            sums[i][qry(s, 0, i)]++;
        }
    }

    cout << ans + N << "\n";
    return 0;
}
