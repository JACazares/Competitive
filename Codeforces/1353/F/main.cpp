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

const int MAXN = 105;
const ll INF = (1LL << 62LL);
int N, M;
ll a[MAXN][MAXN], DP[MAXN][MAXN][2*MAXN];

void solve()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> a[i][j];
    ll delta = a[0][0];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            delta = min(delta, a[i][j]);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            a[i][j] -= delta;
    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = M - 1; j >= 0; j--)
        {
            for(int z = 1; z <= 200; z++)
            {
                int h = i + j + 1 - z;
                if(h > a[i][j])
                {
                    DP[i][j][z] = INF;
                    continue;
                }

                if(i == N - 1 && j == M - 1)
                    DP[i][j][z] = a[i][j] - h;
                else
                {
                    ll down, right;
                    if(i + 1 == N)
                        down = INF;
                    else
                        down = DP[i + 1][j][z] + a[i][j] - h;
                    
                    if(j + 1 == M)
                        right = INF;
                    else
                        right = DP[i][j + 1][z] + a[i][j] - h;
                    DP[i][j][z] = min(down, right);
                }
            }
        }
    }
    ll ans = INF;
    for(int z = 1; z <= 200; z++)
        ans = min(ans, DP[0][0][z]);
    cout << ans << "\n";
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

