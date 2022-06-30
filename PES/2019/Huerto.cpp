#include <iostream>
#define MAXN 5005
#define ONED 1000005

using namespace std;

int N, M, a[155][MAXN], b[3][ONED], preO[3][ONED], pre[155][MAXN], maxim, ans = (1 << 30), tot, arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    if ( N == 1 )
    {
        for ( int i = 1; i <= M; i++ )
            cin >> b[1][i];

        for ( int i = 1; i <= M; i++ )
            preO[1][i] = preO[1][i - 1] + (b[1][i] ? -1 : 1), tot += b[1][i];

        ans = (1 << 30);
        for ( int i = 1; i <= M; i++ )
            ans = min ( ans, tot + preO[1][i] - maxim ), maxim = max ( maxim, preO[1][i] );
    }
    else if ( N == 2 )
    {
        for ( int i = 1; i <= N; i++ )
            for ( int j = 1; j <= M; j++ )
                cin >> b[i][j], tot += b[i][j];

        for ( int i = 1; i <= M; i++ )
            preO[1][i] = preO[1][i - 1] + (b[1][i] ? -1 : 1);

        ans = (1 << 30);
        for ( int i = 1; i <= M; i++ )
            ans = min ( ans, tot + preO[1][i] - maxim ), maxim = max ( maxim, preO[1][i] );

        for ( int i = 1; i <= M; i++ )
            preO[2][i] = preO[2][i - 1] + (b[2][i] ? -1 : 1);

        maxim = 0;
        for ( int i = 1; i <= M; i++ )
            ans = min ( ans, tot + preO[2][i] - maxim ), maxim = max ( maxim, preO[2][i] );

        for ( int i = 1; i <= M; i++ )
            preO[1][i] = preO[1][i - 1] + (b[1][i] ? -1 : 1) + (b[2][i] ? -1 : 1);

        maxim = 0;
        for ( int i = 1; i <= M; i++ )
            ans = min ( ans, tot + preO[1][i] - maxim ), maxim = max ( maxim, preO[1][i] );
    }
    else
    {
        for ( int i = 1; i <= N; i++ )
            for ( int j = 1; j <= M; j++ )
                cin >> a[i][j], pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (a[i][j] ? -1 : 1), tot += a[i][j];

        for ( int x1 = 1; x1 <= N; x1++ )
        {
            for ( int x2 = x1; x2 <= N; x2++ )
            {
                maxim = 0;
                for ( int i = 1; i <= M; i++ )
                {
                    arr[i] = pre[x2][i] - pre[x1 - 1][i] - pre[x2][i - 1] + pre[x1 - 1][i - 1];
                    preO[1][i] = preO[1][i - 1] + arr[i];
                    ans = min ( ans, tot + preO[1][i] - maxim ), maxim = max ( maxim, preO[1][i] );
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
