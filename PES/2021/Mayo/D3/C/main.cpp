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

const int MAXN = 2005;
const ll INF = (1LL << 60LL);
int N, M, sum_c;
ll DP[MAXN*50];
vector<pair<int, pair<int, pll>>> events;

int main()
{
	optimizeIO();
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int c, f, v;
		cin >> c >> f >> v;
		sum_c += c;
		events.pb({f, {1, {c, v}}});
	}
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int c, f, v;
		cin >> c >> f >> v;
		events.pb({f, {0, {c, v}}});
	}
	
	sort(all(events));
	reverse(all(events));
	for(int k = 1; k <= sum_c; k++)
		DP[k] = -INF;
	for(auto i : events)
	{
		int t = i.second.first;
		ll c = i.second.second.first, v = i.second.second.second;
		dbg(i);
		if(t == 1)
		{
			//compra
			for(int k = sum_c; k >= 0; k--)
				if(DP[k] != -INF)
					DP[k + c] = max(DP[k + c], DP[k] - v);
		}
		else if(t == 0)
		{
			//venta
			for(int k = c; k <= sum_c; k++)
				if(DP[k] != -INF)
					DP[k - c] = max(DP[k - c], DP[k] + v);
		}
	}
	
	ll ans = 0;
	for(int k = 0; k <= sum_c; k++)
		ans = max(ans, DP[k]);
	cout << ans << "\n";
	return 0;
}
