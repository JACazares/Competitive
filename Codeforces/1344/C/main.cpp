#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define mp make_pair
#define sz(x) (int)x.size()
#define pb push_back

const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
const ld PI = acos((ld)-1);

int pct(int x) { return __builtin_popcount(x); }

// TO_STRING, credits: Benq
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[i]);
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
	return "("+ts(p.f)+", "+ts(p.s)+")"; }
    
// DEBUG, credits: Benq
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

const int MAXN = 2e5 + 5;
int N, M, in[MAXN], topo_in[MAXN], DP[MAXN], DP2[MAXN];
vi Graph[MAXN], Inv[MAXN];

bool cycles()
{
    queue<int> Q;
    for(int i = 1; i <= N; i++)
        if(topo_in[i] == 0)
            Q.push(i);
    
    vi vis(N + 5, 0);
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        vis[node] = 1;
        for(auto i : Graph[node])
        {
            topo_in[i]--;
            if(topo_in[i] == 0)
                Q.push(i);
        }
    }
    
    for(int i = 1; i <= N; i++)
        if(!vis[i])
            return true;
    return false;
}

int dp(int node)
{
    if(DP[node])
        return DP[node];
    DP[node] = node;
    for(auto i : Graph[node])
        DP[node] = min(DP[node], dp(i));
    return DP[node];
}

int dp2(int node)
{
    if(DP2[node])
        return DP2[node];
    DP2[node] = node;
    for(auto i : Inv[node])
        DP2[node] = min(DP2[node], dp2(i));
    return DP2[node];
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].pb(v);
        Inv[v].pb(u);
        in[v]++;
        topo_in[v]++;
    }
    
    int univ = 0;
    string ans = "";
    if(cycles())
        cout << "-1\n";
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(!DP[i])
                dp(i);
            if(!DP2[i])
                dp2(i);
            if(DP[i] == i && DP2[i] == i)
            {
                univ++;
                ans += "A";
            }
            else
                ans += "E";
        }
        cout << univ << "\n";
        cout << ans << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
