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
        int N, K;
        cin >> N >> K;
        int a[N];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        int minim[N], maxim[N];
        for(int i = 0, j = N - 1; i < j; i++, j--)
        {
            minim[i] = min(a[i], a[j]);
            maxim[i] = max(a[i], a[j]);
        }
        
        vi BIT(2*K + 5, 0);
        for(int i = 0; i < N/2; i++)
        {
            for(int pos = 2; pos <= 2*K + 1; pos += (pos & -pos))
                BIT[pos] += 2;
            for(int pos = minim[i] + 1; pos <= 2*K + 1; pos += (pos & -pos))
                BIT[pos]--;
            for(int pos = minim[i] + maxim[i]; pos <= 2*K + 1; pos += (pos & -pos))
                BIT[pos]--;
            for(int pos = minim[i] + maxim[i] + 1; pos <= 2*K + 1; pos += (pos & -pos))
                BIT[pos]++;
            for(int pos = maxim[i] + K + 1; pos <= 2*K + 1; pos += (pos & -pos))
                BIT[pos]++;
            for(int pos = K + K + 1; pos <= 2*K + 1; pos += (pos & -pos))
                BIT[pos] -= 2;
        }
        int ans = (1 << 30);
        for(int i = 2; i <= K + K; i++)
        {
            int aux = 0;
            for(int pos = i; pos; pos -= (pos & -pos))
                aux += BIT[pos];
            ans = min(ans, aux);
        }
        cout << ans << "\n";
    }
    return 0;
}
