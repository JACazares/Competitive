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

const int MAXN = 2e5 + 5;
int N;
pii a[MAXN];
vi b[MAXN];

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + N);
    int nums = 0;
    for(int i = 0; i < N; i++)
    {
        if(i && a[i].first == a[i - 1].first)
            b[nums - 1].pb(a[i].second);
        else
            b[nums++].pb(a[i].second);
    }
    
    int cnt = b[0].size(), ans = 0;
    for(int i = 0; i < nums; i++)
        sort(b[i].begin(), b[i].end());
    for(int i = 1; i < nums; i++)
    {
        if(b[i][0] < b[i - 1][b[i-1].size() - 1])
        {
            for(int j = 0; j < b[i].size(); j++)
                if(b[i][j] > b[i - 1][b[i-1].size() - 1])
                    cnt++;
            ans = max(ans, cnt);
            cnt = 0;
            for(int j = 0; j < b[i - 1].size(); j++)
                if(b[i - 1][j] < b[i][0])
                    cnt++;
        }
        cnt += b[i].size();
    }
    for(int i = 0; i < nums - 1; i++)
    {
        int r = 0;
        for(int l = 0; l < b[i].size(); l++)
        {
            for(; r < b[i + 1].size(); r++)
                if(b[i + 1][r] > b[i][l])
                    break;
            ans = max(ans, (int)(l + b[i + 1].size() - r + 1));
        }
    }
    ans = max(ans, cnt);
    cnt = 0;
    cout << N - ans << "\n";
    for(int i = 0; i < nums; i++)
        b[i].clear();
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

