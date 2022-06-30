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

const int MAXN = (int)2e5 + 5;
int N, a[MAXN], ans;
vpi b;
ll BIT[MAXN], ST[MAXN];
priority_queue<ll> PQ;

void upd(int pos, int x)
{
	for(; pos <= N; pos += pos&-pos)
		BIT[pos] += x;
}

ll qry(int pos)
{
	ll res = 0;
	for(; pos; pos -= pos&-pos)
		res += BIT[pos];
	return res;
}

void build2()
{
	for(int pos = 0; pos <= 2*N + 1; pos++)
		ST[pos] = (1LL << 62LL);
}

ll qry2(int l, int r)
{
	l += N + 1, r += N + 2;
	ll res = (1LL << 62LL);
	for(; l < r; l/=2, r/=2)
	{
		if(l&1)
			res = min(res, ST[l++]);
		if(r&1)
			res = min(res, ST[--r]);
	}
	return res;
}

void upd2(int pos, ll x)
{
	pos += N + 1;
	for(; pos; pos /= 2)
		ST[pos] = min(ST[pos], x);
}

int main()
{
	optimizeIO();
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		if(a[i] >= 0)
		{
			upd(i, a[i]);
			ans++;
		}
		else
			b.pb({-a[i], i});
	}
	sort(all(b));
	build2();
	ll minim = qry(N), sum = 0;
	for(auto i : b)
	{
		dbg(i, qry(i.second), qry2(i.second, N));
		if(qry(i.second) >= i.first && qry2(i.second, N) - sum >= 0)
		{
			upd2(i.second, qry(i.second));
			sum += i.first;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
