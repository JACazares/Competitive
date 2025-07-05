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

const int MAXN = (int)2e5 + 5;
int N, x, y;
int freq[MAXN][4];
string S, dirs = "DULR";

int main()
{
	optimizeIO();
	cin >> N;
	cin >> S;
	cin >> x >> y;
	S = " " + S;
	for(int i = 1; i <= N; i++)
		for(int c = 0; c < 4; c++)
			freq[i][c] = freq[i - 1][c] + (S[i] == dirs[c]);
	
	int s = 0, e = N, mid, val, ans = -1;
	while(s <= e)
	{
		mid = (s + e) / 2;
		val = 0;
		for(int i = 1; i + mid - 1 <= N; i++)
		{
			int r = i + mid - 1;

			if(r > N)
				break;
			
			int new_x = (freq[N][3] - freq[r][3] + freq[i - 1][3]) - (freq[N][2] - freq[r][2] + freq[i - 1][2]);
			int new_y = (freq[N][1] - freq[r][1] + freq[i - 1][1]) - (freq[N][0] - freq[r][0] + freq[i - 1][0]);

			if(abs(x - new_x) + abs(y - new_y) <= mid && ((abs(x - new_x) + abs(y - new_y))&1) == (mid&1))
				val = 1;
		}

		if(val)
		{
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}

	cout << ans << "\n";
	return 0;
}


