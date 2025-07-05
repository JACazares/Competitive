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

const int INF = (1 << 30);

int main()
{
	optimizeIO();
	int N;
	cin >> N;

	vi a(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	
	string b;
	cin >> b;

	int running = 1;
	int min_l = -INF, max_l = INF;
	int min_r = -INF, max_r = INF;
	for(int i = 1; i < N; i++)
	{
		if(b[i] == b[i - 1])
		{
			if(running >= 4)
			{
				int elem = a[i-4];
				for(int j = i-3; j <= i; j++)
				{
					if(b[i] == '0')
						elem = max(elem, a[j]);
					else
						elem = min(elem, a[j]);
				}

				dbg(b[i]);
				if(b[i] == '0')
					max_l = min(max_l, elem);
				else
					min_r = max(min_r, elem);
				dbg(min_r, max_r, min_l, max_l);
			}
			running++;
		}
		else
		{
			int elem = a[i-4];
			for(int j = i-3; j <= i; j++)
			{
				if(b[i] == '0')
					elem = min(elem, a[j]);
				else
					elem = max(elem, a[j]);
			}

			dbg("CHANGE", b[i]);
			if(b[i] == '0')
				max_r = min(max_r, elem - 1);
			else
				min_l = max(min_l, elem + 1);
			dbg(min_r, max_r, min_l, max_l);

			running = 1;
		}
	}

	min_l = max(min_l, -(int)1e9);
	max_r = min(max_r, (int)1e9);
	cout << min_l << " " << max_r << "\n";
	return 0;
}


