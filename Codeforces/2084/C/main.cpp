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
	
	vi inv(N + 1, 0), idx_a(N + 1, 0);
	for(int i = 0; i < N; i++)
	{
		inv[a[i]] = b[i];
		idx_a[a[i]] = i;
	}

	int id = 0;
	for(int i = 1; i <= N; i++)
	{
		if(inv[inv[i]] != i)
		{
			cout << "-1\n";
			return;
		}
		if(inv[i] == i)
			id++;
	}

	if(N%2 == 0 && id > 0)
	{
		cout << "-1\n";
		return;
	}

	if(N%2 == 1 && id != 1)
	{
		cout << "-1\n";
		return;
	}

	dbg(inv, idx_a);

	vpi ops;
	for(int i = 0; i < N; i++)
	{
		if(inv[a[i]] == a[i] && i != N/2)
		{
			ops.push_back({i, N/2});
			idx_a[a[i]] = N/2;
			idx_a[a[N/2]] = i;
			swap(a[i], a[N/2]);
			break;
		}
	}

	for(int i = 0, j = N - 1; i < j; i++, j--)
	{
		dbg(a[i], idx_a[inv[a[i]]], i, j);
		if(idx_a[inv[a[i]]] != j)
		{
			int x = idx_a[inv[a[i]]], y = j;
			ops.push_back({x, y});
			idx_a[a[y]] = x;
			idx_a[a[x]] = y;
			swap(a[x], a[y]);
		}
		dbg(a);
	}

	cout << ops.size() << "\n";
	for(auto [i, j] : ops)
		cout << i+1 << " " << j+1 << "\n";
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


