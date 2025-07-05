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

const int MAXN = 305;
int n, k, a[MAXN][MAXN];

void solve()
{
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int l = 0; l < n; l++)
            a[i][l] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int l = 0; l < k / (n - i); l++)
            a[i][(i + l) % n] = 1;
        k -= (k / (n - i));
    }
    
    int minim = n, maxim = 0, aux = 0;
    for(int i = 0; i < n; i++)
    {
        aux = 0;
        for(int l = 0; l < n; l++)
            aux += a[i][l];
        minim = min(minim, aux);
        maxim = max(maxim, aux);
    }
    ans = (maxim - minim) * (maxim - minim);
    minim = n, maxim = 0;
    for(int l = 0; l < n; l++)
    {
        aux = 0;
        for(int i = 0; i < n; i++)
            aux += a[i][l];
        minim = min(minim, aux);
        maxim = max(maxim, aux);
    }
    ans += (maxim - minim) * (maxim - minim);
    cout << ans << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int l = 0; l < n; l++)
            cout << a[i][l];
        cout << "\n";
    }
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

