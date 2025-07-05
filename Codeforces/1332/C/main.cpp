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
    int T;
	cin >> T;
	while(T--)
    {
        int N, K;
        string S;
        cin >> N >> K;
        cin >> S;
        int a[N][26];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 26; j++ )
                a[i][j] = 0;
        for(int i = 0; i < N; i++)
            a[i%K][S[i]-'a']++;
        int ans = 0;
        for(int i = 0, j = K - 1; i <= j; i++, j--)
        {
            int maxim = 0, freq[N];
            for(int k = 0; k < 26; k++)
            {
                freq[k] = a[i][k] + a[j][k];
                maxim = max(maxim, freq[k]);
            }

            if(i == j)
                ans += maxim/2;
            else
                ans += maxim;
        }
        cout << N - ans << "\n";
    }
	return 0;
}
