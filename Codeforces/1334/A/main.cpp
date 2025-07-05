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
        int p[N], c[N], ans = 1;
        for(int i = 0; i < N; i++)
        {
            cin >> p[i] >> c[i];
            if(p[i] < c[i])
                ans = 0;
            if(i > 0)
            {
                if(p[i] < p[i - 1] || c[i] < c[i - 1])
                    ans = 0;
                if(c[i] - c[i - 1] > p[i] - p[i - 1])
                    ans = 0;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
