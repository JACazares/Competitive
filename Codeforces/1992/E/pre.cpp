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

ll op(vi& digits, int a, int b)
{
	int d = digits.size();
	int curr = d - 1;

	if(d*a - b > d+4)
		return 0;

	ll ans = 0;
	for(int i = 0; i < d*a - b; i++)
	{
		ans *= 10;
		ans += digits[curr];
		curr--;
		if(curr < 0)
			curr = d - 1;
	}

	return ans;
}

int main()
{
	optimizeIO();
	const int MAX = 10000;
	vi d = {0, 1};
	for(int n = 2; n <= 100; n++)
	{
		int aux = n;
		vi digits;
		while(aux > 0)
		{
			digits.pb(aux%10);
			aux /= 10;
		}

		for(int a = 1; a <= MAX; a++)
		{
			for(int b = 1; b <= MAX; b++)
			{
				if(b > n*a)
					break;
				if(n*a-b == op(digits, a, b) && n*a-b != 0)
					cout << "ans[" << n << "].pb({" << a << "," << b << "});\n";
			}
		}
	}

	return 0;
}


