#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve(ll n, ll pot, ll a)
{
    if(pot == 1)
        return a + 1;

    ll k = pot / 4;
    ll l = (n - 1) / 3;
    ll group = l / k;
    
    if(group == 0)
        return solve((n - 1) % (3*pot/4) + 1, pot / 4, a + pot - pot/4);
    else if(group == 1)
        return solve((n - 1) % (3*pot/4) + 1, pot/4, a + pot + pot/4);
    else if(group == 2)
        return solve((n - 1) % (3*pot/4) + 1, pot/4, a + pot + pot/2);
    else
        return solve((n - 1) % (3*pot/4) + 1, pot/4, a + pot);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        ll N;
        cin >> N;
        ll pot, p = 0;
        for(pot = 1; pot <= N; pot *= 4)
        {
            if(N <= 3*pot)
                break;
            p++;
            N -= 3*pot;
        }
        
        if(N % 3 == 1)
        {
            cout << pot + (N - 1)/3 << "\n";
            continue;
        }
        
        ll aux = solve(N, pot, pot);
        if(N % 3 == 2)
            cout << aux << "\n";
        else
            cout << ((pot + N/3 - 1) ^ aux) << "\n";
    }
    return 0;
}

/*
    int cont = 1, cnt = 0;
    const int C = 256;
    vi used(100, 0), S;
    while(cont)
    {
        cont = 0;
        for(int i = 64; i <= C; i++)
        {
            if(used[i])
                continue;
            for(int j = 64; j <= C; j++)
            {
                if(used[j])
                    continue;
                for(int k = 64; k <= C; k++)
                {
                    if(used[k] || (i^j^k) != 0)
                        continue;
                    used[i] = 1;
                    used[j] = 1;
                    used[k] = 1;
                    cout << i << " " << j << " " << k << "\n";
                    cnt++;
                    if(cnt % 4 == 0)
                        cout << "\n";
                    if(cnt % 16 == 0)
                        cout << "\n";
                    cont = 1;
                    break;
                }
                if(cont)
                    break;
            }
            if(cont)
                break;
        }
    }
    return 0;
}
*/

/*
1. a que potencia de 4 pertenece (1, 4, 64, etc.)
2. dentro de esa potencia, en que grupito esta? (4 grupos, orden 1-3-4-2)

e.j.
    64-1 = 128
    64-2 = 144
    64-3 = 160
    64-4 = 176
*/
