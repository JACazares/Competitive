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

const int MAXN = (int)5e3 + 5;
int N, S[MAXN], p[MAXN];

int look(int x)
{
	if(p[x] == x)
		return p[x];
	return p[x] = look(p[x]);
}

void join(int a, int b)
{
	p[look(a)] = look(b);
}

void step(int x)
{
	if(x > N)
		return;
	S[x]--;
	if(S[x] == 1)
		join(x, x + 1);
	
	if(x + S[x] + 1 <= N)
		step(look(x + S[x] + 1));
}

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> S[i];
	
	for(int i = 0; i <= N + 3; i++)
		p[i] = i;
	
	for(int i = 1; i <= N; i++)
		if(S[i] == 1)
			join(i, i + 1);

	ll ans = 0;
	for(int i = 1; i <= N; i++)
	{
		if(S[i] > max(1, N - i))
		{
			ans += S[i] - max(1, N - i);
			S[i] = max(1, N - i);
		}
		while(S[i] > 1)
		{
			step(i);
			ans++;
		}
	}
	cout << ans << "\n";
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
