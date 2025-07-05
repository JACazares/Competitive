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
	vi a(N), b(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 0; i < N; i++)
		cin >> b[i];
	
	sort(all(a));
	sort(all(b));
	dbg(a, b);

	vi freq(10, 0);
	int rpnt = N - 1;
	int ans = 0;
	for(int i = N - 1; i >= 0; i--)
	{
		if(a[i] <= 9)
		{
			freq[a[i]]++;
			continue;
		}

		if(rpnt == -1)
		{
			a[i] = int(log10(a[i])) + 1;
			ans++;
			freq[a[i]]++;
			continue;
		}

		dbg(i, rpnt, a[i], b[rpnt], ans);
		dbg(freq);
		

		while(rpnt >= 0 && a[i] < b[rpnt])
		{
			b[rpnt] = int(log10(b[rpnt])) + 1;
			ans++;
			freq[b[rpnt]]--;
			rpnt--;
		}

		if(rpnt >= 0 && a[i] == b[rpnt])
		{
			rpnt--;
			continue;
		}
		else if(rpnt >= 0 && a[i] > b[rpnt])
		{
			a[i] = int(log10(a[i])) + 1;
			ans++;
			freq[a[i]]++;
			continue;
		}
	}

	while(rpnt >= 0)
	{
		if(b[rpnt] <= 9)
		{
			freq[b[rpnt]]--;
			rpnt--;
			continue;
		}

		b[rpnt] = int(log10(b[rpnt])) + 1;
		ans++;
		freq[b[rpnt]]--;
		rpnt--;
	}
	dbg(freq);

	for(int i = 2; i < 10; i++)
		ans += abs(freq[i]);
	
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


