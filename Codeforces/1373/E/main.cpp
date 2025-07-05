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

#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

int pct(int x) { return __builtin_popcount(x); }
template<class T> T ceil(T a, T b) {
    return ((a)/(b) + ((a)%(b) ? 1 : 0)); }
template<class T> T floor(T a, T b) {
    return ((a)/(b)); }

// TO_STRING, credits: Benq
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; for(int i = 0; i < SZ; i++) res += char('0'+b[i]);
	return res; }
template<class A, class B> string ts(pair<A,B> p);
template<class T> string ts(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> string ts(pair<A,B> p) {
	return "("+ts(p.first)+", "+ts(p.second)+")"; }
    
// DEBUG, credits: Benq
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int N, K;
vi ans;

void solve()
{
    ans.clear();
    cin >> N >> K;

    ll num = 2*N - K*(K+1);
    ll den = 2*K + 2;
    
    ll sum = 0;
    if(num >= 0 && num % den == 0)
    {
        sum = num/den;
        if(sum >= 9 - K)
        {
            ans.pb(9-K);
            sum -= (9 - K);
        }
        while(sum >= 9)
        {
            ans.pb(9);
            sum -= 9;
        }
        if(sum > 0)
            ans.pb(sum);
        reverse(all(ans));
        if(ans.empty())
            ans.pb(0);
        for(auto i : ans)
            cout << i;
        cout << "\n";
        return;
    }
    
    dbg(num, den);
    for(int c1 = 1; c1 <= 40; c1++)
    {
        for(int c2 = 1; c2 <= K; c2++)
        {
            ll d = 9*c1*c2;
            if(num + 2*d >= 0 && (num + 2*d) % den == 0)
            {
                dbg(c1, c2, d);
                ans.clear();
                sum = (num + 2*d)/den;
                ans.pb(9 + c2 - K);
                sum -= (9 + c2 - K);
                for(int i = 0; i < c1 - 1; i++)
                {
                    ans.pb(9);
                    sum -= 9;
                }
                if(sum >= 8)
                {
                    ans.pb(8);
                    sum -= 8;
                }
                while(sum >= 9)
                {
                    ans.pb(9);
                    sum -= 9;
                }
                if(sum > 0)
                {
                    ans.pb(sum);
                    sum = 0;
                }
                reverse(all(ans));
                if(sum == 0)
                {
                    for(auto i : ans)
                        cout << i;
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

