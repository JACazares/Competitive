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
	string A, B, C;
	cin >> A >> B;
	cin >> C;

	int N = A.length();
	int M = B.length();

	vector<vi> DP(N + 1, vi(M + 1, 0));
	for(int i = N; i >= 0; i--)
		for(int j = M; j >= 0; j--)
		{
			int k = i + j;
			if(A[i] == C[k] && i < N)
				DP[i][j] = max(DP[i][j], DP[i + 1][j] + 1);
			if(B[j] == C[k] && j < M)
				DP[i][j] = max(DP[i][j], DP[i][j + 1] + 1);
			
			if(i < N)
				DP[i][j] = max(DP[i][j], DP[i + 1][j]);
			if(j < M)
				DP[i][j] = max(DP[i][j], DP[i][j + 1]);
		}
	
	cout << N + M - DP[0][0] << "\n";
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


