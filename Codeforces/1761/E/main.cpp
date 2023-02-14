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

vi vis;
vector<vi> Graph, components;
vi curr_comp;

void dfs(int node)
{
	vis[node] = 1;
	curr_comp.pb(node + 1);
	for(auto i : Graph[node])
		if(!vis[i])
			dfs(i);
}

void solve()
{
	int N;
	cin >> N;
	
	Graph.clear();
	Graph.resize(N);
	vis.clear();
	vis.resize(N, 0);
	components.clear();
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			char x;
			cin >> x;
			if(x == '1')
				Graph[i].pb(j);
		}
	
	for(int i = 0; i < N; i++)
	{
		if(!vis[i])
		{
			curr_comp.clear();
			dfs(i);
			components.pb(curr_comp);
		}
	}
	
	auto cmp = [](vi a, vi b) { return sz(a) < sz(b); };
	sort(all(components), cmp);
	dbg(components);
	
	if(sz(components[0]) == N)
	{
		cout << "0\n";
		return;
	}
	
	for(auto i : components)
	{
		int minim = sz(i) - 1, node = 0;
		for(auto x : i)
			if(sz(Graph[x-1]) < minim)
			{
				minim = sz(Graph[x-1]);
				node = x;
			}

		if(minim < sz(i) - 1)
		{
			cout << "1\n" << node << "\n";
			return;
		}
	}
			
	if(sz(components[0]) == 1)
	{
		cout << "1\n" << components[0][0] << "\n";
		return;
	}
		
	if(sz(components) >= 3)
	{
		cout << "2\n" << components[0][0] << " " << components[1][0]<< "\n";
		return;
	}
	
	cout << sz(components[0]) << "\n";
	for(auto i : components[0])
		cout << i << " ";
	cout << "\n";
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
