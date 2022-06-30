#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

vector<string> str;
set<string> nums;

void precalc(string s = "", int n = 0, int o = 0)
{
    if(n == 8)
    {
        if(o == 8 || o == 0)
            return;
        nums.insert(s);
        str.pb(s);
        return;
    }

    precalc(s + "0", n + 1, o);
    precalc(s + "1", n + 1, o + 1);
}

random_device rd;
mt19937 gen(rd());

int transform_cnt(string A, string B)
{
    int ret = 0;
    for(int i = 0; i < 8; i++)
        if(A[i] != B[i])
            ret++;
    return ret;
}

string transform_str(string A, string B)
{
    string ret = "";
    for(int i = 0; i < 8; i++)
    {
        if(A[i] != B[i])
            ret += "1";
        else
            ret += "0";
    }
    return ret;
}

int N;

void solve()
{
    if(N == -1)
        exit(0);
    
    N = 8;
    string guess = "11111111";
    while(N > 0)
    {
        cout << guess << "\n";
        cin >> N;
        cerr << guess << " " << N << "\n";
        if(N == 0 || N == -1)
            return;
        
        vector<string> keep;
        keep.clear();
        for(auto i : nums)
            if(transform_cnt(i, guess) == N)
                keep.pb(transform_str(i, guess));

        nums.clear();
        for(auto i : keep)
        {
            nums.insert(i);
            cerr << " " << i << "\n";
        }

        if(!keep.empty())
            guess = keep[0];
        else
        {
            N = -1;
            exit(0);
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        precalc();
        solve();
    }
    return 0;
}
