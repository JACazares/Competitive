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

const int x = 1e7 + 5;
int prime[x];

void criba()
{
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 4; i <= x; i += 2)
        prime[i] = 2;
    for(int i = 3; i*i <= x; i += 2)
        if(!prime[i])
            for(int j = i*i; j <= x; j += i)
                prime[j] = i;
}

const int MAXN = 5e5 + 5;
int N, a, aux, a1[MAXN], b1[MAXN];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        aux = a;
        vi pfac;
        while(prime[a])
        {
            pfac.pb(prime[a]);
            a /= prime[a];
        }
        pfac.pb(a);
        dbg(pfac);
        sort(pfac.begin(), pfac.end());
        int cnt = 1, ans = 0;
        for(int l = 1; l < pfac.size(); l++)
        {
            if(pfac[l - 1] != pfac[l])
            {
                ans = 1;
                break;
            }
            cnt++;
        }
        if(!ans)
        {
            a1[i] = -1;
            b1[i] = -1;
        }
        else
        {
            a1[i] = 1;
            for(int l = 0; l < cnt; l++)
                a1[i] *= pfac[0];
            b1[i] = aux / a1[i];
        }
    }
    for(int i = 0; i < N; i++)
        cout << a1[i] << " ";
    cout << "\n";
    for(int i = 0; i < N; i++)
        cout << b1[i] << " ";
    cout << "\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

