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

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second

int pct(int x) { return __builtin_popcount(x); }

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
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h);
    if (sizeof...(t))
        cerr << ", ";
	DBG(t...);
}

#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define optimizeIO() 0
#define openFiles() 0
#else
#define dbg(...) 0
#define optimizeIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define openFiles() freopen("file.in", "r", stdin); freopen("file.out", "w", stdout)
#endif

const int MAXN = 205;
int n;
char a[MAXN][MAXN];

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    
    
    int cnt1 = 0, cnt2 = 0;
    if(a[0][1] == '0')
        cnt1++;
    else
        cnt2++;

    if(a[1][0] == '0')
        cnt1++;
    else
        cnt2++;

    if(a[n-1][n-2] == '1')
        cnt1++;
    else
        cnt2++;

    if(a[n-2][n-1] == '1')
        cnt1++;
    else
        cnt2++;
    
    vpi ans;
    if(cnt1 < cnt2)
    {
        if(a[0][1] == '0')
            ans.pb({0, 1});
        if(a[1][0] == '0')
            ans.pb({1, 0});
        if(a[n-1][n-2] == '1')
            ans.pb({n-1, n-2});
        if(a[n-2][n-1] == '1')
            ans.pb({n-2, n-1});
    }
    else
    {
        if(a[0][1] == '1')
            ans.pb({0, 1});
        if(a[1][0] == '1')
            ans.pb({1, 0});
        if(a[n-1][n-2] == '0')
            ans.pb({n-1, n-2});
        if(a[n-2][n-1] == '0')
            ans.pb({n-2, n-1});
    }
    
    cout << sz(ans) << "\n";
    for(auto i : ans)
        cout << i.first + 1 << " " << i.second + 1 << "\n";
}

int main ()
{
    optimizeIO();
    //openFiles();
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
