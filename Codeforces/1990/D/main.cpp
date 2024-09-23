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
	int N;
	cin >> N;
	vi a(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	a.pb(0);

	vector<vi> DP(N+1, vi(4, 0));
	for(int i = N - 1; i >= 0; i--)
	{
		for(int pd = 0; pd <= 3; pd++)
		{
			DP[i][pd] = DP[i + 1][0] + 1;
			for(int d = 0; d <= 3; d++)
			{
				if(pd == 0)
				{
					if(d == 0 && a[i] > 0)
						continue;
					if(d == 1 && a[i] > 2)
						continue;
					if(d >= 2)
						continue;
				}
				else if(pd == 1)
				{
					if(d <= 1 && a[i] > 2)
						continue;
					if(d == 2 && a[i] > 3)
						continue;
					if(d == 3 && a[i] > 4)
						continue;
				}
				else if(pd == 2)
				{
					if(d == 0 && a[i] > 0)
						continue;
					if(d == 1 && a[i] > 3)
						continue;
					if(d >= 2)
						continue;
				}
				else if(pd == 3)
				{
					if(d == 0 && a[i] > 0)
						continue;
					if(d == 1 && a[i] > 4)
						continue;
					if(d >= 2)
						continue;
				}

				DP[i][pd] = min(DP[i][pd], DP[i + 1][d] + (d > 0));
			}
		}
	}
	cout << DP[0][0] << "\n";
	dbg(DP[0][0]);
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


