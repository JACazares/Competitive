#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 1e5 + 5;
string S;
int N, v[2], l0[MAXN], l1[MAXN], r0[MAXN], r1[MAXN];
ll x, y;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    cin >> x >> y;
    N = S.length();
    S = " " + S;
    
    if(x > y)
    {
        //minimize x (left)
        for(int i = 1; i <= N; i++)
        {
            l0[i] = l0[i - 1] + (S[i] == '0' || S[i] == '?');
            l1[i] = l1[i - 1] + (S[i] == '1');
        }
        for(int i = N; i >= 1; i--)
        {
            r0[i] = r0[i + 1] + (S[i] == '0' || S[i] == '?');
            r1[i] = r1[i + 1] + (S[i] == '1');
        }
        
        ll ans = 0;
        for(int i = 1; i <= N; i++)
        {
            if(S[i] == '0' || S[i] == '?')
                ans += l1[i - 1] * y;
            if(S[i] == '1')
                ans += l0[i - 1] * x;
        }
        ll minim = ans;
        
        int q = 0;
        for(int i = 1; i <= N; i++)
        {
            if(S[i] == '?')
            {
                ans -= (l1[i - 1] * y + r1[i + 1] * x);
                ans += (l0[i - 1] * x + r0[i + 1] * y);
                minim = min(minim, ans);
                q++;
            }
            l1[i] += q;
            l0[i] -= q;
        }
        
        cout << minim << "\n";
    }
    else
    {
        //minimize y (right )
        for(int i = 1; i <= N; i++)
        {
            l0[i] = l0[i - 1] + (S[i] == '0');
            l1[i] = l1[i - 1] + (S[i] == '1' || S[i] == '?');
        }
        for(int i = N; i >= 1; i--)
        {
            r0[i] = r0[i + 1] + (S[i] == '0');
            r1[i] = r1[i + 1] + (S[i] == '1' || S[i] == '?');
        }
        
        ll ans = 0;
        for(int i = 1; i <= N; i++)
        {
            if(S[i] == '0')
                ans += l1[i - 1] * y;
            if(S[i] == '1' || S[i] == '?')
                ans += l0[i - 1] * x;
        }
        ll minim = ans;
        
        int q = 0;
        for(int i = 1; i <= N; i++)
        {
            if(S[i] == '?')
            {
                ans -= (l0[i - 1] * x + r0[i + 1] * y);
                ans += (l1[i - 1] * y + r1[i + 1] * x);
                minim = min(minim, ans);
                q++;
            }
            l0[i] += q;
            l1[i] -= q;
        }
        
        cout << minim << "\n";
    }
    return 0;
}
