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

const int MAXN = 2e5 + 5, LOG = 30;
int N, M, Q, p[MAXN], a[MAXN], MP[MAXN], pos[MAXN], nxt[MAXN][LOG], last[MAXN];

int main ()
{
    optimizeIO();
    //openFiles();
    cin >> N >> M >> Q;
    for(int i = 0; i < N; i++)
    {
        cin >> p[i];
        MP[p[i]] = i;
    }
    for(int i = 0; i < M; i++)
        cin >> a[i];
    
    for(int i = 1; i <= N; i++)
        pos[i] = -1;

    for(int i = M - 1; i >= 0; i--)
    {
        nxt[i][0] = pos[p[(MP[a[i]] + 1) % N]];
        for(int k = 1; k < LOG; k++)
        {
            if(nxt[i][k - 1] == -1)
                nxt[i][k] = -1;
            else
                nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
        }
        dbg(i, nxt[i][0]);
        pos[a[i]] = i;
    }
    
    last[M] = -1;
    for(int i = M - 1; i >= 0; i--)
    {
        int aux = N - 1;
        last[i] = i;
        for(int k = LOG - 1; k >= 0; k--)
            if((1 << k) <= aux && last[i] != -1)
            {
                last[i] = nxt[last[i]][k];
                aux -= (1 << k);
            }

        if(last[i] == -1)
            last[i] = last[i + 1];
        else if(last[i + 1] != -1)
            last[i] = min(last[i], last[i + 1]);
        dbg(i, last[i]);
    }

    for(int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if(last[l] != -1 && last[l] <= r)
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
