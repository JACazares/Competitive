#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e3 + 5;
int N, K, DP[MAXN][MAXN], ans[MAXN][MAXN], dist[10];
string S[MAXN], num[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> S[i];
    DP[N][0] = 1;
    for(int i = N - 1; i >= 0; i--)
    {
        for(int n = 0; n <= 9; n++)
        {
            dist[n] = 0;
            for(int j = 0; j < 7; j++)
                if(S[i][j] == '0' && num[n][j] == '1')
                    dist[n]++;
            for(int j = 0; j < 7; j++)
                if(S[i][j] == '1' && num[n][j] == '0')
                    dist[n] = K + 1;
        }

        for(int k = 0; k <= K; k++)
            for(int n = 9; n >= 0; n--)
                if(k - dist[n] >= 0 && DP[i + 1][k - dist[n]])
                {
                    ans[i][k] = n;
                    DP[i][k] = 1;
                    break;
                }
    }
    if(!DP[0][K])
        cout << "-1\n";
    else
    {
        int tK = K, start = 0;
        for(int i = 0; i < N; i++)
        {
            if(ans[i][tK] > 0)
                start = 1;
            if(start)
                cout << ans[i][tK];
            for(int n = 9; n >= 0; n--)
            {
                dist[n] = 0;
                for(int j = 0; j < 7; j++)
                    if(S[i][j] == '0' && num[n][j] == '1')
                        dist[n]++;
                for(int j = 0; j < 7; j++)
                    if(S[i][j] == '1' && num[n][j] == '0')
                        dist[n] = K + 1;
                if(tK - dist[n] >= 0 && DP[i + 1][tK - dist[n]])
                {
                    tK = tK - dist[n];
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
