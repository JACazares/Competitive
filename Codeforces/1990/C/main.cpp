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

ll triangle(ll x)
{
	return x * (x + 1) / 2;
}

void solve()
{
	int N;
	cin >> N;
	vl a(N), freq(N+1, 0);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	
	ll sum = 0, maxim = 0;
	for(int i = 0; i < N; i++)
	{
		sum += a[i];
		freq[a[i]]++;
		if(freq[a[i]] >= 2)
			maxim = max(maxim, a[i]);
		a[i] = maxim;
	}

	dbg(a);

	freq.clear();
	freq.resize(N+1, 0);
	maxim = 0;
	for(int i = 0; i < N; i++)
	{
		sum += a[i];
		freq[a[i]]++;
		if(freq[a[i]] >= 2)
			maxim = max(maxim, a[i]);
		a[i] = maxim;
	}

	dbg(a);

	a.push_back(0);
	ll diff_idx = N;
	for(int i = N - 1; i >= 0; i--)
	{
		if(a[i] == a[i+1])
			continue;
		sum += (diff_idx - i) * a[i+1] * (N-1 - diff_idx) + a[i+1] * triangle(diff_idx - i);
		diff_idx = i;
	}
	cout << sum << "\n";
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
