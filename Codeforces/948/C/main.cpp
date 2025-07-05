#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
long long N, c[MAXN], p[MAXN], pre[MAXN], ans[MAXN], sums[MAXN], sum;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> c[i];
    for(int i = 1; i <= N; i++)
    {
        cin >> p[i];
        sums[i] = sums[i - 1] + p[i];
    }

    for(int i = 1; i <= N; i++)
    {
        int s = i, e = N, mid, idx = i - 1;
        while(s <= e)
        {
            mid = (s + e) / 2;

            if(sums[mid] - sums[i - 1] <= c[i])
            {
                idx = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        //cerr << i << " " << idx << "\n";
        pre[i]++;
        pre[idx + 1]--;
        ans[idx + 1] += c[i] - (sums[idx] - sums[i - 1]);
        //cerr << " " << c[i] - (sums[idx] - sums[i - 1]) << "\n";
    }

    for(int i = 1; i <= N; i++)
    {
        pre[i] += pre[i - 1];
        //cerr << pre[i] << " ";
        ans[i] += pre[i] * p[i];
    }
    //cerr << "\n";

    for(int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
