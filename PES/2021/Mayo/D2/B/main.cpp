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

const int MAXN = (int)5e4 + 5, MAXK = 25;
int N, K;
ll p[MAXN], t[MAXN], DP[MAXN][MAXK];
ll sum_p[MAXN], sum_t[MAXN], le[MAXN], ri[MAXN];

void precalc()
{
	for(int i = 1; i <= N + 1; i++)
		sum_t[i] = sum_t[i - 1] + t[i];
	for(int i = 1; i <= N + 1; i++)
		sum_p[i] = sum_p[i - 1] + p[i];
		
	for(int i = 1; i <= N; i++)
		le[i] = p[i]*sum_t[i] + le[i - 1];
	for(int i = N; i >= 1; i--)
		ri[i] = p[i]*(sum_t[N] - sum_t[i]) + ri[i + 1];
	
	return;
}

ll getL(int l, int r)
{
	return le[r] - le[l-1] - (sum_p[r] - sum_p[l-1])*sum_t[l];
}

ll getR(int l, int r)
{
	return ri[l] - ri[r+1] - (sum_p[r] - sum_p[l-1])*(sum_t[N]-sum_t[r]);
}

int find_piv(int l, int r)
{
    int s = l, e = r, mid, val, ans = e;
    while(s <= e)
    {
        mid = (s + e)/2;
        if(sum_t[mid] - sum_t[l] >= sum_t[r] - sum_t[mid])
            val = 1;
        else
            val = 0;

        if(val)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

void solve(int k, int lI, int rI, int lJ, int rJ)
{
	if(lI > rI)
        return;
		
	int mid = (lI + rI)/2;
    int opt = max(lJ, mid+1);
	
	DP[mid][k] = (1LL << 60LL);
	for(int j = max(lJ, mid + 1); j <= rJ; j++)
	{
		int piv = find_piv(mid, j);
		ll ans_l = getL(mid, piv - 1);
		ll ans_r = getR(piv, j);
		
		if(DP[j][k-1] + ans_l + ans_r < DP[mid][k])
		{
			opt = j;
			DP[mid][k] = DP[j][k - 1] + ans_l + ans_r;
		}
	}
	
	solve(k, lI, mid - 1, lJ, opt);
	solve(k, mid + 1, rI, opt, rJ);
	return;
}

int main()
{
	optimizeIO();
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> p[i];
	for(int i = 2; i <= N; i++)
		cin >> t[i];
	precalc();
	
	for(int i = 1; i <= N; i++)
		DP[i][0] = getL(i, N);
	for(int k = 1; k <= K; k++)
		DP[N][k] = 0;
		
	for(int k = 1; k <= K; k++)
		solve(k, 1, N - 1, 1, N);
	cout << DP[1][K] << "\n";
	return 0;
}
