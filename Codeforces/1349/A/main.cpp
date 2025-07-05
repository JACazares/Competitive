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

const int MAXN = 1e5 + 5, INF = (1 << 30);
int N, a[MAXN];
map<int, vi> primes;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        for(int x = 2; x*x <= a[i]; x++)
        {
            while(a[i] % x == 0)
            {
                primes[x].push_back(i);
                a[i] /= x;
            }
        }
        if(a[i] != 1)
            primes[a[i]].push_back(i);
    }
    ll ans = 1;
    for(auto i : primes)
    {
        map<int, int> MP;
        for(auto j : i.second)
            MP[j]++;
        dbg(i);dbg(MP);
        
        int minim = INF, snd = INF;
        for(auto j : MP)
        {
            if(j.second < minim)
            {
                snd = minim;
                minim = j.second;
            }
            else if(j.second < snd)
                snd = j.second;
        }
        dbg(MP.size());
        if(MP.size() == N - 1)
        {
            snd = minim;
            minim = 0;
        }
        if(MP.size() <= N - 2)
        {
            snd = 0;
            minim = 0;
        }
        dbg(minim); dbg(snd);
        if(snd == INF)
            snd = 0;
        ans *= pow(i.first, snd);
    }
    cout << ans << "\n";
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

