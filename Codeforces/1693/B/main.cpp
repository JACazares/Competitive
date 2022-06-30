#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
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

const int MAXN = 2e5 + 5;
int N, p[MAXN], child[MAXN];
ll l[MAXN], r[MAXN];
vi Graph[MAXN];
priority_queue<pli> PQ;

void leaves(int node)
{
	for(auto i : Graph[node])
	{
		leaves(i);
		child[node]++;
	}
	if(!child[node])
		PQ.push({r[node], node});
}

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		Graph[i].clear();
		child[i] = 0;
	}
	for(int i = 2; i <= N; i++)
	{
		cin >> p[i];
		Graph[p[i]].pb(i);
	}
	for(int i = 1; i <= N; i++)
		cin >> l[i] >> r[i];
	
	leaves(1);
	int ans = 0;
	while(!PQ.empty())
	{
		auto aux = PQ.top();
		PQ.pop();
		
		int node = aux.second;
		ll val = aux.first;
		dbg(node);
		bool inpath = 1;
		ans++;
		while(node != 0)
		{
			val = min(val, r[node]);
			
			l[node] -= val;
			r[node] -= val;
			if(inpath && l[node] <= 0 && 0 <= r[node] && node != 1)
				child[p[node]]--;
			
			if(l[node] > 0)
			{
				if(inpath && child[node] == 0)
					PQ.push({r[node], node});
				inpath = 0;
			}
			node = p[node];
		}
	}
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
