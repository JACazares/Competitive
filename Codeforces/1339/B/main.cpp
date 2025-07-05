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
        int a[N], b[N];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        sort(a, a + N);
        for(int i = 0, j = N - 1; i <= j; i++, j--)
        {
            b[2*i] = a[i];
            if(2*i + 1 < N)
                b[2*i + 1] = a[j];
        }
        reverse(b, b + N);
        for(int i = 0; i < N; i++)
            cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}
