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

const int MAXN = 1e3 + 5, INF = (1 << 30);
int N, M;
char a;

void solve()
{
	int min_x = INF, max_x = 0, min_y = INF, max_y = 0;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
		{
			cin >> a;
			if(a == 'B')
			{
				min_x = min(min_x, i+j-1);
				max_x = max(max_x, i+j-1);
				min_y = min(min_y, i+M-j);
				max_y = max(max_y, i+M-j);
			}
		}
	
	int ans = -1, ans_i = 1, ans_j = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
		{
			int aux_i = 0, aux_j = 0, aux = 0;
			aux_i = max(abs((i+j-1) - min_x), abs(max_x - (i+j-1)));
			aux_j = max(abs((i+M-j) - min_y), abs(max_y - (i+M-j)));
			aux = max(aux_i, aux_j);
			if(ans == -1 || aux < ans)
			{
				ans_i = i;
				ans_j = j;
				ans = aux;
			}
		}
	cout << ans_i << " " << ans_j << "\n";
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
