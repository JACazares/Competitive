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

const int MAXN = 2e5 + 5;
const ll INF = 1LL << 40LL;
ll N, a[MAXN], pre[MAXN], l[MAXN], r[MAXN];
ll ST1[2*MAXN], ST2[2*MAXN];
stack<pll> S;

ll qry1(int _l, int _r)
{
	_l += N+1, _r += N+2;
	ll ret = INF;
	for(; _l < _r; _l/=2, _r/=2)
	{
		if(_l&1)
			ret = min(ret, ST1[_l++]);
		if(_r&1)
			ret = min(ret, ST1[--_r]);
	}
	return ret;
}

ll qry2(int _l, int _r)
{
	_l += N+1, _r += N+2;
	ll ret = -INF;
	for(; _l < _r; _l/=2, _r/=2)
	{
		if(_l&1)
			ret = max(ret, ST2[_l++]);
		if(_r&1)
			ret = max(ret, ST2[--_r]);
	}
	return ret;
}

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	while(!S.empty())
		S.pop();
	for(int i = 1; i <= N; i++)
	{
		while(!S.empty() && S.top().first <= a[i])
			S.pop();
			
		int prv = 1;
		if(!S.empty())
			prv = S.top().second + 1;
		S.push({a[i], i});
		l[i] = prv;
	}
	while(!S.empty())
		S.pop();
	
	for(int i = N; i >= 1; i--)
	{
		while(!S.empty() && S.top().first <= a[i])
			S.pop();
			
		int nxt = N;
		if(!S.empty())
			nxt = S.top().second - 1;
		S.push({a[i], i});
		r[i] = nxt;
	}
	while(!S.empty())
		S.pop();
	
	for(int i = N+1; i < 2*(N+1); i++)
	{
		ST1[i] = pre[i-N-1];
		ST2[i] = pre[i-N-1];
	}
	for(int i = N; i > 0; i--)
	{
		ST1[i] = min(ST1[2*i], ST1[2*i + 1]);
		ST2[i] = max(ST2[2*i], ST2[2*i + 1]);
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(qry2(i, r[i]) - qry1(l[i]-1, i-1) > a[i])
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
