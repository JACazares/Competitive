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
int N, A, R, M;
ll a[MAXN], pre[MAXN], add, rm, minim, aux, ans = (1LL << 62LL);

ll f(int i, ll h)
{
    aux = 0;
    add = i*h - pre[i];
    rm = (pre[N] - pre[i]) - (h*(N - i));
    if(M < A + R)
    {
        minim = min(add, rm);
        aux += M*minim;
        add -= minim;
        rm -= minim;
    }

    aux += rm*R + add*A;
    dbg(i, h, aux);
    return aux;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> R >> M; 
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    sort(a + 1, a + N + 1);
    for(int i = 1; i <= N; i++)
        pre[i] = pre[i - 1] + a[i];
    
    for(int i = 1; i < N; i++)
    {
        ll s = a[i], e = a[i + 1];
        dbg(s, e);
        while(s < e - 2)
        {
            int left_third = s + (e - s) / 3;
            int right_third = e - (e - s) / 3;
            
            if(f(i, left_third) > f(i, right_third))
                s = left_third;
            else
                e = right_third;
            dbg(s, e);
        }
        ans = min(ans, min(f(i, s), min(f(i, min(e, s + 1)), f(i, min(e, s + 2)))));
    }
    cout << ans << "\n";
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

