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

const int MAXN = 1e5 + 5;
int N, M, Q, p[MAXN], u[MAXN], v[MAXN], ans[MAXN];
vector<pair<pii, pair<pii, int>>> qry[MAXN][2];

int look(int node)
{
	if(p[node] == node)
		return node;
	return p[node] = look(p[node]);
}

void join(int a, int b)
{
	p[look(a)] = look(b);
}

void solve()
{
	cin >> N >> M >> Q;
	for(int i = 1; i <= N; i++)
		p[i] = i;
	for(int i = 1; i <= M; i++)
		cin >> u[i] >> v[i];
		
	for(int i = 0; i < Q; i++)
	{
		int l, r;
		cin >> l >> r;
		qry[M/2][0].pb({{l, r}, {{0, M}, i}});
	}

	for(int k = 0; k <= 20; k++)
	{
		for(int i = 1; i <= N; i++)
			p[i] = i;
		for(int i = 0; i <= M; i++)
		{
			if(i > 0)
				join(u[i], v[i]);
			for(auto j : qry[i][k&1])
			{
				int l = j.fst.fst, r = j.fst.snd;
				int L = j.snd.fst.fst, R = j.snd.fst.snd;
				int idx = j.snd.snd;
				//cerr << l << " " << r << " " << L << " " << R << " " << idx << "\n";
				
				if(look(l) == look(r))
				{
					if(L != R)
						qry[(L+i)/2][(k+1)&1].pb({{l, r}, {{L, i}, idx}});
					ans[idx] = i;
				}
				else
				{
					if(L != R)
						qry[(i+R+1)/2][(k+1)&1].pb({{l, r}, {{i+1, R}, idx}});
				}
			}
			qry[i][k&1].clear();
		}	
	}
	
	for(int i = 0; i < Q; i++)
		cout << ans[i] << " ";
	cout << "\n";
}

int main()
{
	optimizeIO();
	int T = 1;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
