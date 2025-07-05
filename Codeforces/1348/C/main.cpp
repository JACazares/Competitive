#include <iostream>
#include <algorithm>
#include <cmath>
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
        string S;
        cin >> N >> K;
        cin >> S;
        sort(S.begin(), S.end());
        int d1 = 0;
        vi vis(26, 0);
        for(int i = 0; i < K; i++)
        {
            if(!vis[S[i] - 'a'])
                d1++;
            vis[S[i] - 'a'] = 1;
        }
        cout << S[K - 1];
        if(d1 == 1)
        {
            vis.clear();
            vis.resize(26);
            int d2 = 0;
            for(int i = K; i < N; i++)
            {
                if(!vis[S[i] - 'a'])
                    d2++;
                vis[S[i] - 'a'] = 1;
            }
            if(d2 > 1)
            {
                for(int i = K; i < N; i++)
                    cout << S[i];
            }
            else
            {
                //N - K letters left, divide between K spaces, take the fall
                int left = ceil((double)(N - K) / K);
                for(int i = K; i < K + left; i++)
                    cout << S[i];
            }
        }
        cout << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
