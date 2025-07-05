#include <iostream>

using namespace std;

const int MAXN = (int)1e6 + 5;
int N, Q, BIT[MAXN];

void upd(int pos, int val)
{
    for(; pos <= N; pos += pos & -pos)
        BIT[pos] += val;
}

int qry(int pos)
{
    int sum = 0;
    for(; pos; pos -= pos & -pos)
        sum += BIT[pos];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        upd(val, 1);
    }
    
    for(int i = 0; i < Q; i++)
    {
        int val;
        cin >> val;
        if(val > 0)
            upd(val, 1);
        else
        {
            val *= -1;
            int s = 1, e = N, mid, sum, ans = 0;
            while(s <= e)
            {
                mid = (s + e) / 2;
                sum = qry(mid);
                
                if(sum >= val)
                {
                    ans = mid;
                    e = mid - 1;
                }
                else if(sum < val)
                    s = mid + 1;
            }
            upd(ans, -1);
        }
    }
    
    for(int i = 1; i <= N; i++)
        if(BIT[i] != 0)
        {
            cout << i << "\n";
            return 0;
        }
    cout << "0\n";
    return 0;
}
