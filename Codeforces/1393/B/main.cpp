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

const int MAXN = 1e5 + 5;
int N, Q, a[MAXN], freq[MAXN], used[MAXN];

int main ()
{
    optimizeIO();
    //openFiles();
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        used[freq[a[i]]]++;
    }
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        char t;
        int x;
        cin >> t >> x;
        int d = 0;
        if(t == '+')
            d = 1;
        else
            d = -1;
        freq[x] += d;
        
        if(d == 1)
            used[freq[x]]++;
        else
            used[freq[x] + 1]--;
        
        int ans = 0;
        if(used[8] >= 2 || (used[6] >= 1 && used[2] >= 2)
            || (used[4] >= 2) || (used[4] >= 1 && used[2] >= 3))
            ans = 1;
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
