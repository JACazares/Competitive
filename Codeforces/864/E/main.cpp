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

struct Item
{
	int t, d, p, i;
	
	bool operator<(const Item& x) const
	{
		if(d == x.d)
			return i < x.i;
		return d < x.d;
	}
};

int main()
{
	optimizeIO();
	int N;
	cin >> N;
	vector<Item> item(N);
	for(int i = 0; i < N; i++)
	{
		cin >> item[i].t >> item[i].d >> item[i].p;
		item[i].i = i + 1;
	}
	sort(all(item));
	
	vector<vi> DP(N + 1, vi(2001, 0));
	for(int i = N - 1; i >= 0; i--)
	{
		for(int t = 0; t <= 2000; t++)
		{
			DP[i][t] = 0;
			if(t + item[i].t < item[i].d)
				DP[i][t] = max(DP[i][t], DP[i + 1][t + item[i].t] + item[i].p);
			DP[i][t] = max(DP[i][t], DP[i + 1][t]);
		}
	}

	vi items;
	int curr_t = 0;
	for(int i = 0; i < N; i++)
	{
		if(DP[i][curr_t] == DP[i + 1][curr_t])
			continue;
		else
		{
			curr_t += item[i].t;
			items.push_back(item[i].i);
		}
	}

	cout << DP[0][0] << "\n";
	cout << items.size() << "\n";
	for(auto i : items)
		cout << i << " ";
	cout << "\n";
	return 0;
}


