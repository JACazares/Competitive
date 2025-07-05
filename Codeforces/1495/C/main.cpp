#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
int N, M, del[MAXN][MAXN], sum[MAXN];
char a[MAXN][MAXN], ans[MAXN][MAXN];

void solve()
{
    cin >> N >> M;
    for(int i = 0; i <= N; i++)
    {
        sum[i] = 0;
        for(int j = 0; j <= M; j++)
        {
            a[i][j] = ' ';
            del[i][j] = 0;
            ans[i][j] = '.';
        }
    }
    
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < M; j++)
            cin >> a[i][j];
        int chck = 0;
        for(int j = M - 1; j > 0; j--)
        {
            if(a[i][j] == '.')
                continue;
            if(chck > 0 && i%2 == 1 && i < N - 1)
                del[i - 1][j + 1] = 1;
            chck++;
        }
        sum[i] = chck;
    }
    
    for(int i = 0; i < N; i += 2)
    {
        for(int j = 0; j < M; j++)
            if(!del[i][j])
                ans[i][j] = 'X';
        
        if(i < N - 1)
        {
            for(int j = 0; j < M; j++)
                ans[i + 1][j] = a[i + 1][j];
            
            if(sum[i + 1] == 0)
                ans[i + 1][0] = 'X';
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << ans[i][j];
        cout << "\n";
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;   
}
