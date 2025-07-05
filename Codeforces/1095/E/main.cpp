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

const int MAXN = (int)1e6 + 5;
int N;
vi pre, minim;
string S;

int main()
{
	optimizeIO();
	cin >> N;
	cin >> S;

	pre.resize(N);
	pre[0] = (S[0] == '(' ? 1 : -1);
	for(int i = 1; i < N; i++)
		pre[i] = pre[i - 1] + (S[i] == '(' ? 1 : -1);
	
	minim.resize(N);
	minim[N - 1] = pre[N - 1];
	for(int i = N - 2; i >= 0; i--)
		minim[i] = min(minim[i + 1], pre[i]);
	
	dbg(pre, minim);

	int curr_min = pre[0], ans = 0, delta = 0;
	delta = 0;
	if(S[0] == '(')
		delta = -2;
	else
		delta = 2;
	
	if(pre[0] + delta >= 0 && minim[1] + delta >= 0 && pre[N - 1] + delta == 0)
		ans++;

	for(int i = 1; i < N - 1; i++)
	{
		delta = 0;
		if(S[i] == '(')
			delta = -2;
		else
			delta = 2;

		if(curr_min >= 0 && pre[i] + delta >= 0 && minim[i + 1] + delta >= 0 && pre[N - 1] + delta == 0)
			ans++;

		curr_min = min(curr_min, pre[i]);
	}
	delta = 0;
	if(S[N - 1] == '(')
		delta = -2;
	else
		delta = 2;
	
	if(curr_min >= 0 && pre[N - 1] + delta == 0)
		ans++;
	
	cout << ans << "\n";
	return 0;
}


