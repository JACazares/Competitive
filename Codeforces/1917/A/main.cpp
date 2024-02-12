#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

void solve()
{
    int N;
    cin >> N;
    vi a(N);

    int sgn = 1;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        if(a[i] > 0)
            sgn *= 1;
        else if(a[i] == 0)
            sgn *= 0;
        else if(a[i] < 0)
            sgn *= -1;
    }

    if(sgn == 1)
        cout << "1\n1 0\n";
    else
        cout << "0\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}