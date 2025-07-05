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

const int MAXN = 55;
int N, M, good, vis[MAXN][MAXN];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char a[MAXN][MAXN];
vpi bad;

bool valid(int x, int y)
{
    if(x < 0 || x >= N)
        return false;
    if(y < 0 || y >= M)
        return false;
    if(a[x][y] == '#')
        return false;
    if(vis[x][y])
        return false;
    return true;
}

void dfs(int x, int y)
{
    if(!valid(x, y))
        return;
    if(a[x][y] == 'G')
        good--;
    if(a[x][y] == 'B')
        good = -1;
    vis[x][y] = 1;
    
    for(int k = 0; k < 4; k++)
        dfs(x + dx[k], y + dy[k]);
}

void solve()
{
    cin >> N >> M;
    good = 0;
    bad.clear();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            vis[i][j] = 0;
            cin >> a[i][j];
            if(a[i][j] == 'B')
                bad.pb({i, j});
            if(a[i][j] == 'G')
                good++;
        }
    
    for(auto i : bad)
    {
        for(int k = 0; k < 4; k++)
        {
            if(valid(i.first + dx[k], i.second + dy[k])
                && a[i.first + dx[k]][i.second + dy[k]] == '.')
            {
                a[i.first + dx[k]][i.second + dy[k]] = '#';
            }
        }
    }
    
    dfs(N - 1, M - 1);
    if(good == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
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

