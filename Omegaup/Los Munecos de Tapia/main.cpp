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

const int MAXN = (int)2e5 + 5, MAXP = (int)1e5 + 5;
int N, P, M, a[MAXN];
vi m[MAXP];

int main()
{
	optimizeIO();
	cin >> N >> P >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
		m[a[i]].pb(i);
	}
	int ans = 0;
	for(int x = 1; x <= P; x++)
	{
		int rpnt = 1, sum = 0;
		dbg(x);
		dbg(m[x]);
		for(int i = 0; i < sz(m[x]); i++)
		{
			for(rpnt = max(rpnt, i + 1); rpnt < sz(m[x]); rpnt++)
			{
				if(sum + m[x][rpnt] - m[x][rpnt - 1] - 1 > M)
					break;
				sum += m[x][rpnt] - m[x][rpnt - 1] - 1;
			}
			dbg(i, rpnt, sum);
			ans = max(ans, rpnt - i);
			if(i + 1 < sz(m[x]) && rpnt > i + 1)
				sum += m[x][i] - m[x][i + 1] + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
