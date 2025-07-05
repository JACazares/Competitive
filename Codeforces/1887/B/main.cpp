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

int N, T, K;
bool vis[MAXN];
vi freq[MAXN];
vpi Graph[MAXN];

int main()
{
	optimizeIO();
	cin >> N >> T;
	for(int t = 1; t <= T; t++)
	{
		int M;
		cin >> M;
		for(int i = 0; i < M; i++)
		{
			int u, v;
			cin >> u >> v;
			Graph[u].pb({v, t});
			Graph[v].pb({u, t});
		}
	}

	cin >> K;
	for(int i = 1; i <= K; i++)
	{
		int x;
		cin >> x;
		freq[x].pb(i);
	}

	priority_queue<pii> search_queue;
	search_queue.push({0, 1});
	while(!search_queue.empty())
	{
		auto [k, node] = search_queue.top();
		search_queue.pop();
		k = -k;
		dbg(k, node);
		if(node == N)
		{
			cout << k << "\n";
			return 0;
		}

		if(vis[node])
			continue;
		vis[node] = 1;
		
		for(auto [v, t] : Graph[node])
		{
			if(vis[v])
				continue;
			
			auto nxt = upper_bound(freq[t].begin(), freq[t].end(), k);
			if(nxt == freq[t].end())
				continue;
			search_queue.push({-(*nxt), v});
		}
	}

	cout << "-1\n";
	return 0;
}


