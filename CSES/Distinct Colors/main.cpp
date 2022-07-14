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
int N, res;
vi color, sz, ans;
int colors[MAXN];
vector < vi > Graph;
 
void pre ( int node, int p = 0 )
{
	sz[node] = 1;
	for ( auto i : Graph[node] )
		if ( i != p )
			pre ( i, node ), sz[node] += sz[i];
}
 
void upd ( int node, int p, int x )
{
	colors[color[node]] += x;
	if ( colors[color[node]] == 1 && x == 1 )
		res++;
	if ( colors[color[node]] == 0 && x == -1 )
		res--;
	for ( auto i : Graph[node] )
		if ( i != p )
			upd ( i, node, x );
}
 
void solve ( int node, bool keep, int p = 0 )
{
	int maxsz = 0, bignode = -1;
	for ( auto i : Graph[node] )
		if ( i != p && sz[i] > maxsz )
			maxsz = sz[i], bignode = i;
	
	for ( auto i : Graph[node] )
		if ( i != p && i != bignode )
			solve ( i, 0, node );
	if ( bignode != -1 )
		solve ( bignode, 1, node );
 
	for ( auto i : Graph[node] )
		if ( i != p && i != bignode )
			upd ( i, node, 1 );
 
	colors[color[node]]++;
	if ( colors[color[node]] == 1 )
		res++;
	
	ans[node] = res;
	
	if ( !keep )
		upd ( node, p, -1 );
}
 
int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	color.resize ( N + 1 );
	sz.resize ( N + 1 );
	Graph.resize ( N + 1 );

	vi aux_color;
	map<int, int> mp;
	for ( int i = 1; i <= N; i++ )
	{
		cin >> color[i];
		aux_color.pb(color[i]);
	}
	sort(all(aux_color));
	for(int i = 0; i < sz(aux_color); i++)
		mp[aux_color[i]] = i;
	for(int i = 1; i <= N; i++)
		color[i] = mp[color[i]];

	int u, v;
	for ( int i = 0; i < N - 1; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	pre ( 1 );
	ans.resize ( N + 1 );
	solve ( 1, 0 );
	for ( int i = 1; i <= N; i++ )
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}