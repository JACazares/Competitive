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
	int N, P;
	cin >> N >> P;
	vi a(N);
	map<int, int> cnt, cnt2;
	cnt.clear();
	cnt2.clear();
	for(int i = N - 1; i >= 0; i--)
	{
		cin >> a[i];
		cnt[a[i]] = 1;
	}
	cnt2[0] = 1;
	for(int i = 1; i < N; i++)
	{
		cnt2[(a[i] + 1) % P] = 1;
		if(a[i] != P - 1)
			break;
	}
	if(a[N - 1] == P - 1)
		cnt2[1] = 1;
	
	int ans = P - 1, carry = 1;
	if(a[0] == 0)
	{
		for(int i = P - 1; i > a[0]; i--)
		{
			if(cnt[i])
				ans--;
			else
				break;
		}
	}
	else
	{
		for(int i = a[0] - 1; i > 0; i--)
		{
			if(cnt[i])
				ans--;
			else
			{
				carry = 0;
				if(cnt2[i])
					ans--;
				else
					break;
			}
		}
		if(carry && cnt[0])
		{
			ans--;
			for(int i = P - 1; i > a[0]; i--)
			{
				if(cnt[i])
					ans--;
				else
					break;
			}
		}
	}

	cout << ans << "\n";
}

int main()
{
	optimizeIO();
	int T = 1;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
