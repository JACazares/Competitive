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
#define all(x) x.begin(), x.end()
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

const int MAXN = 2e5 + 5;
int N, M, t[MAXN], d[MAXN], zero, p[MAXN], used[MAXN];
vi ind[MAXN];

int look(int node)
{
    if(p[node] == node)
        return node;
    return p[node] = look(p[node]);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> t[i];
        ind[t[i]].pb(i);
    }
    for(int i = 1; i < N; i++)
    {
        d[i] = t[i] - t[i - 1];
        if(d[i] == 0)
            zero++;
    }
    for(int i = 1; i <= M; i++)
        p[i] = i;
    cout << N - zero - 1 << "\n";
    vi idx;
    for(int i = 1; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if(ind[look(a)].size() > ind[look(b)].size())
            swap(a, b);
        idx.clear();
        for(auto j : ind[look(a)])
        {
            idx.pb(j);
            used[j] = i;
        }
        sort(all(idx));
        for(auto j : idx)
        {
            ind[look(b)].pb(j);
            //upd t,d
            t[j] = look(b);
            if(j > 0)
            {
                if(d[j] == 0)
                    zero--;
                d[j] = t[j] - t[j - 1];
                if(d[j] == 0)
                    zero++;
            }
            if(j < N - 1 && used[j + 1] != i)
            {
                if(d[j + 1] == 0)
                    zero--;
                d[j + 1] = t[j + 1] - t[j];
                if(d[j + 1] == 0)
                    zero++;
            }
        }
        ind[look(a)].clear();
        p[look(a)] = look(b);
        cout << N - zero - 1 << "\n";
    }
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

