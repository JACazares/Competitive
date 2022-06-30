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

int N, K;
string S;

void solve()
{
	cin >> N >> K;
	cin >> S;
	
	int ans = 0;
	ans += 10*(S[0] - '0');
	for(int i = 1; i < N - 1; i++)
		ans += 11*(S[i] - '0');
	ans += (S[N-1] - '0');
	
	int cnt = 0;
	for(int i = 0; i < N; i++)
		cnt += (S[i] - '0');
	
	int l = 0, r = N - 1;
	for(; l < N; l++)
		if(S[l] == '1')
			break;
	for(; r >= 0; r--)
		if(S[r] == '1')
			break;
	
	if(cnt > 0)
	{
		if(r < N - 1 && N - 1 - r <= K)
		{
			K -= (N - 1 - r);
			ans -= 10;
			if(cnt == 1 && r == 0)
				ans++;
			if(cnt > 1 && l > 0 && l <= K)
			{
				K -= l;
				ans -= 1;
			}
		}
		else if(l > 0 && l <= K && l != N - 1)
		{
			K -= l;
			ans -= 1;
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
