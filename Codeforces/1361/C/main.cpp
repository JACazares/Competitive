#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define mp make_pair
#define sz(x) (int)x.size()
#define pb push_back

int pct(int x) { return __builtin_popcount(x); }
template<class T> T ceil(T a, T b) {
    return ((a)/(b) + ((a)%(b) ? 1 : 0)); }
template<class T> T floor(T a, T b) {
    return ((a)/(b)); }

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
	return "("+ts(p.first)+", "+ts(p.second)+")"; }
    
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

const int MAXN = 1e6 + 5;
int N, A[MAXN], B[MAXN], a[MAXN], b[MAXN], maxim;
vpi Graph[(1 << 21)];
pii p[(1 << 21)];

int look(int node)
{
    if(p[node].first == node)
        return node;
    return p[node].first = look(p[node].first);
}

void join(int na, int nb)
{
    if(look(na) == look(nb))
        return;
    p[look(na)].second += p[look(nb)].second;
    p[look(nb)].first = look(na);
}

int deg[MAXN];

void cycle()
{
    for(int i = 0; i <= maxim; i++)
        deg[i] = Graph[i].size();
    stack<pii> path;
    vi ans;
    vi vis(N, 0);
    pii node = {a[0], 0};
    path.push(node);
    while(!path.empty())
    {
        if(deg[node.first])
        {
            path.push(node);
            auto v = Graph[node.first].back();
            Graph[node.first].pop_back();
            deg[node.first]--;
            while(deg[node.first] && vis[v.second])
            {
                v = Graph[node.first].back();
                Graph[node.first].pop_back();
                deg[node.first]--;
            }
            if(vis[v.second])
            {
                node = path.top();
                path.pop();
            }
            else
            {
                dbg(node, v);
                vis[v.second] = 1;
                node = v;
            }
        }
        else
        {
            if(a[node.second] == node.first)
            {
                ans.pb(node.second * 2 + 1);
                ans.pb(node.second * 2 + 2);
            }
            else
            {
                ans.pb(node.second * 2 + 2);
                ans.pb(node.second * 2 + 1);
            }
            node = path.top();
            path.pop();
        }
    }
    
    for(int i = 0; i < ans.size() - 2; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
        maxim = max(maxim, max(A[i], B[i]));
    }
    
    int br = 0, k;
    vi freq(maxim + 1);
    for(k = 0; k <= 20; k++)
    {
        for(int i = 0; i <= maxim; i++)
        {
            freq[i] = 0;
            p[i] = {i, 0};
        }

        for(int i = 0; i < N; i++)
        {
            a[i] = A[i] & ((1 << k) - 1);
            b[i] = B[i] & ((1 << k) - 1);
            p[a[i]].second++;
            p[b[i]].second++;
            freq[a[i]] = (freq[a[i]] + 1) % 2;
            freq[b[i]] = (freq[b[i]] + 1) % 2;
        }

        for(int i = 0; i <= maxim; i++)
            if(freq[i] == 1)
                br = 1;

        for(int i = 0; i < N; i++)
            join(a[i], b[i]);
        if(p[look(a[0])].second < 2*N)
            br = 1;

        if(br)
            break;
    }
    --k;
    cout << k << "\n";
    for(int i = 0; i < N; i++)
    {
        a[i] = A[i] & ((1 << k) - 1);
        b[i] = B[i] & ((1 << k) - 1);
        Graph[a[i]].pb({b[i], i});
        Graph[b[i]].pb({a[i], i});
    }
    
    cycle();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

