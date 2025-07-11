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
	vpi gifts(N);
	for(int i = 0; i < N; i++)
	{
		cin >> gifts[i].first >> gifts[i].second;
		gifts[i].second = -gifts[i].second;
	}
	
	sort(all(gifts));
	dbg(gifts);

	int ans = -1;
	int maxim = 0;
	int rpnt = N - 1;
	for(int i = N - 2; i >= 0; i--)
	{
		if(gifts[i].first != gifts[i + 1].first)
		{
			if(rpnt != i + 1)
			{
				for(int j = i + 1; j <= rpnt; j++)
				{
					if(ans == -1)
						ans = abs(gifts[i+1].first - max(maxim, -gifts[j].second));
					ans = min(ans, abs(gifts[i+1].first - max(maxim, -gifts[j].second)));
				}
			}
			else
			{
				if(ans == -1)
					ans = abs(gifts[i].first - max(maxim, -gifts[i+1].second));
				ans = min(ans, abs(gifts[i].first - max(maxim, -gifts[i+1].second)));
			}

			for(; rpnt > i; rpnt--)
				maxim = max(maxim, -gifts[i].second);
		}
	}
	if(rpnt != 1)
	{
		for(int j = 0; j <= rpnt; j++)
		{
			if(ans == -1)
				ans = abs(gifts[0].first - max(maxim, -gifts[j].second));
			ans = min(ans, abs(gifts[0].first - max(maxim, -gifts[j].second)));
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		if(ans == -1)
			ans = abs(gifts[N - 1].first + gifts[i].second);
		ans = min(ans, abs(gifts[N - 1].first + gifts[i].second));
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


