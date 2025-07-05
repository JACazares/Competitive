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

const int MAXN = 2e5 + 5;
int R, G, h, DP[2][MAXN];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> G;
    int total = R + G;
    for(h = 1; ; h++)
    {
        if(total - h >= 0)
            total -= h;
        else
            break;
    }
    //h es 1 nivel MAS del total
    
    for(int b = h; b >= 1; b--)
    {
        for(int r = 0; r <= R; r++)
        {
            int g = b*(b-1)/2 - r;
            DP[b%2][r] = 0;
            if(g > G)
                DP[b%2][r] = 0;
            else if(b == h)
                DP[b%2][r] = 1;
            else
            {
                if(r + b <= R)
                    DP[b%2][r] = (DP[(b + 1)%2][r + b] + DP[(b + 1)%2][r]) % MOD;
                else
                    DP[b%2][r] = DP[(b + 1)%2][r];
            }
        }
    }
    cout << DP[1][0] << "\n";
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

