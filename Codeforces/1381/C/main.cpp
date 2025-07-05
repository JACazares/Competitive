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

const int MAXN = 1e5 + 5;
int N, x, y, a[MAXN], freq[MAXN], diff, ans[MAXN];
priority_queue<pii> PQ;
vi pos[MAXN], cyc[MAXN];

void solve()
{
    cin >> N >> x >> y;
    diff = y - x;
    for(int i = 0; i <= N + 1; i++)
    {
        freq[i] = 0;
        ans[i] = 0;
        pos[i].clear();
        cyc[i].clear();
    }

    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        pos[a[i]].pb(i);
    }
    
    while(!PQ.empty())
        PQ.pop();
    
    int unused = 1;
    for(int i = 1; i <= N + 1; i++)
    {
        if(freq[i])
            PQ.push({freq[i], i});
        else
            unused = i;
    }
    
    for(int i = 0; i < N; i++)
        ans[i] = unused;
    
    pii aux;
    while(x--)
    {
        aux = PQ.top();
        PQ.pop();
        
        ans[pos[aux.second][pos[aux.second].size() - 1]] = aux.second;
        pos[aux.second].pop_back();
        freq[aux.second]--;
        if(aux.first - 1 > 0)
            PQ.push({aux.first - 1, aux.second});
    }
    
    int tot_cyc = 0, curr = 0;
    while(!PQ.empty())
    {
        aux = PQ.top();
        PQ.pop();

        tot_cyc = max(tot_cyc, aux.first);
        for(int i = 0; i < aux.first; i++)
        {
            cyc[curr].pb(aux.second);
            curr = (curr + 1) % tot_cyc;
        }
    }
    
    for(int i = 0; i < tot_cyc; i++)
    {
        if(cyc[i].size() == 1)
            continue;
        
        dbg(cyc[i]);

        cyc[i].pb(cyc[i][0]);
        for(int j = 0; j < cyc[i].size() - 1 && diff; j++)
        {
            ans[pos[cyc[i][j + 1]][pos[cyc[i][j + 1]].size() - 1]] = cyc[i][j];
            pos[cyc[i][j + 1]].pop_back();
            diff--;
        }
    }
    
    if(!diff)
    {
        cout << "YES\n";
        for(int i = 0; i < N; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    else
        cout << "NO\n";
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

