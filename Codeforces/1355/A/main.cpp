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

const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
const ld PI = acos((ld)-1);

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
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

ull nxt(ull x)
{
    ull aux = x, ansmin = 9, ansmax = 0;
    while(x)
    {
        ansmin = min(ansmin, x%10);
        ansmax = max(ansmax, x%10);
        x /= 10;
    }
    return aux + ansmin * ansmax;
}

void solve()
{
    ull x, K;
    cin >> x >> K;
    K--;
    while(K--)
    {
        if(nxt(x) == x)
            break;
        x = nxt(x);
    }
    cout << x << "\n";
}

int main ()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T; 
    while(T--)
        solve();
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

