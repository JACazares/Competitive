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

const int MAXN = 3e5 + 5;
int N, a[MAXN], minim[MAXN], maxim[MAXN];
int STmin[2*MAXN], STmax[2*MAXN];
stack<pii> S;

void build()
{
	for(int i = 0; i < N; i++)
	{
		STmin[i + N] = a[i];
		STmax[i + N] = a[i];
	}
	for(int i = N - 1; i > 0; i--)
	{
		STmin[i] = min(STmin[2*i], STmin[2*i+1]);
		STmax[i] = max(STmax[2*i], STmax[2*i+1]);
	}
}

int qrymin(int l, int r)
{
	l += N, r += N + 1;
	int ret = N + 1;
	for(; l < r; l/=2, r/=2)
	{
		if(l&1)
			ret = min(ret, STmin[l++]);
		if(r&1)
			ret = min(STmin[--r], ret);
	}
	return ret;
}

int qrymax(int l, int r)
{
	l += N, r += N + 1;
	int ret = 0;
	for(; l < r; l/=2, r/=2)
	{
		if(l&1)
			ret = max(ret, STmax[l++]);
		if(r&1)
			ret = max(STmax[--r], ret);
	}
	return ret;
}

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	build();
	while(!S.empty())
		S.pop();
	
	//minim
	S.push({-1, N});
	for(int i = N - 1; i >= 0; i--)
	{
		while(S.top().first > a[i])
			S.pop();
		minim[i] = S.top().second - 1;
		S.push({a[i], i});
	}
	while(!S.empty())
		S.pop();
	
	//maxim
	S.push({N + 1, N});
	for(int i = N - 1; i >= 0; i--)
	{
		while(S.top().first < a[i])
			S.pop();
		maxim[i] = S.top().second - 1;
		S.push({a[i], i});
	}
	while(!S.empty())
		S.pop();
	
	int ans = 0;
	for(int i = 0; i < N - 1; )
	{
		int look;
		if(a[i + 1] < a[i])
			dbg(i + 1, maxim[i]), look = qrymin(i + 1, maxim[i]);
		else
			dbg(i + 1, minim[i]), look = qrymax(i + 1, minim[i]);
		
		dbg(i, look);
			
		for(int j = i + 1; j < N; j++)
			if(a[j] == look)
			{
				i = j;
				break;
			}
		ans++;
	}
	cout << ans << "\n";
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
