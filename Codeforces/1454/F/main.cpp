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

const int MAXN = 2e5 + 5;
int N, a[MAXN], ST[2*MAXN];

int qry(int l, int r)
{
    l += N, r += N + 1;
    int ans = (1 << 30);
    for(; l < r; l/=2, r/=2)
    {
        if(l&1)
            ans = min(ans, ST[l++]);
        if(r&1)
            ans = min(ans, ST[--r]);
    }
    return ans;
}

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    
    for(int i = 0; i < N; i++)
        ST[i + N] = a[i];
    for(int i = N - 1; i > 0; i--)
        ST[i] = min(ST[2*i], ST[2*i + 1]);
    
    map<int, int> maxim, l, r;
    maxim[N] = 0;
    for(int i = N - 1; i >= 0; i--)
        maxim[i] = max(maxim[i + 1], a[i]);
    
    for(int i = 0; i < N; i++)
        r[maxim[i]] = i;
    for(int i = N - 1; i >= 0; i--)
        l[maxim[i]] = i;
    
    int aux = 0;
    for(int i = 0; i < N; i++)
    {
        aux = max(aux, a[i]);
        
        int auxL = l[aux];
        int auxR = r[aux];
        if(auxR < i + 2)
            continue;
        auxL = max(auxL, i + 2);
        dbg(i, auxL, auxR);

        int s = auxL - 1, e = auxR - 1, val, ans = -1;
        for(int mid = s; mid <= e; mid++)
        {
            val = qry(i + 1, mid);
            
            if(val == aux)
            {
                dbg(i, mid, val);
                ans = mid;
                break;
            }
        }
        
        if(ans > -1)
        {
            cout << "YES\n";
            cout << i + 1 << " " << ans - i << " " << N - ans - 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
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
