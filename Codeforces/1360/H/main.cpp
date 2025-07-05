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
template<class T> T ceil(T a, T b) {
    return ((a)/(b) + ((a)%(b) ? 1 : 0)); }

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

const int MAXN = 105;
ll N, M, k, pos[MAXN];
string s[MAXN];
map<ll, int> MP;

void solve()
{
    cin >> N >> M;
    k = (1LL << M) - N;
    MP.clear();
    for(int i = 0; i < N; i++)
    {
        cin >> s[i];
        pos[i] = 0;
        for(int j = 0; j < M; j++)
        {
            pos[i] *= 2;
            pos[i] += (s[i][j] - '0');
        }
        MP[pos[i]] = 1;
    }
    sort(pos, pos + N);

    ll s1 = 0, e = (1LL << M), mid, val, ans;
    while(s1 <= e)
    {
        mid = (s1 + e) / 2;
        val = mid;
        for(int i = 0; i < N; i++)
            if(pos[i] <= mid)
                val--;
        
        if(val < (k - 1) / 2)
            s1 = mid + 1;
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    while(MP[ans]) ans++;
    dbg(ans);
    string S;
    for(int i = 0; i < M; i++)
    {
        S += (ans % 2 ? "1" : "0");
        ans /= 2;
    }
    while(S.length() < M) S += "0";
    reverse(S.begin(), S.end());
    cout << S << "\n";
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

//IF USE CEIL/FLOOR, CAST TO INT

