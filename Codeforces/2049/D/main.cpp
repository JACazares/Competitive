#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second
 
int pct(int x) { return __builtin_popcount((unsigned int)x); }
 
// TO_STRING, credits: Benq
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[(unsigned long)i]);
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
#else
#define dbg(...) 0
#define optimizeIO() ios_base::sync_with_stdio(false); cin.tie(nullptr)
#endif

void solve()
{
	int N, M;
	ll K;
	cin >> N >> M >> K;

	vector<vl> a(N+1, vl(M, 0)), f(N+1, vl(M, 0));
	vector<vector<vl>> g(N+1, vector<vl>(M, vl(M, 0)));
	for(int i = 1; i <= N; i++)
		for(int j = 0; j < M; j++)
			cin >> a[i][j];
	
	
	for(int j = 0; j < M; j++)
	{
		for(int s = 0; s < M; s++)
			g[0][j][s] = K*s;
		f[0][j] = K*j;
	}

	for(int i = 1; i <= N; i++)
		for(int j = 0; j < M; j++)
		{
			for(int s = 0; s < M; s++)
			{
				if(i == 1)
				{
					if(j > 0)
						g[i][j][s] = g[i][j - 1][s] + a[i][(j + s) % M];
					else
						g[i][j][s] = K*s + a[i][(j + s) % M];
				}
				else
				{
					if(j > 0)
						g[i][j][s] = min(f[i - 1][j] + K*s , g[i][j - 1][s]) + a[i][(j + s) % M];
					else
						g[i][j][s] = f[i - 1][j] + K*s + a[i][(j + s) % M];
				}
				dbg(i, j, s, g[i][j][s]);
			}

			f[i][j] = g[i][j][0];
			for(int s = 1; s < M; s++)
				f[i][j] = min(f[i][j], g[i][j][s]);
			dbg(i, j, f[i][j]);
		}
	
	cout << f[N][M - 1] << "\n";
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}


