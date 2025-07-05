#include <bits/stdc++.h>

using namespace std;
template<int D, typename T>
struct vec : public vector<vec<D - 1, T>> {
  static_assert(D >= 1, "vector dimension must be greater than zero!");
  template<typename... Args>
  vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {
  }
};
template<typename T>
struct vec<1, T> : public vector<T> {
  vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vec<1, int> vi;
typedef vec<1, ll> vl;
typedef vec<1, pii> vpi;
typedef vec<1, pll> vpl;

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

const int MAXN = 1005, INF = (1 << 30);
int N, a[MAXN][MAXN];
int DP[2][MAXN][MAXN], cnt[2][MAXN][MAXN];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];
    
    for(int i = N - 1; i >= 0; i--)
        for(int k = 0; k < 2; k++)
        {
            DP[k][i][N] = INF;
            DP[k][N][i] = INF;
        }

    pii pos{-1, -1};
    for(int i = N - 1; i >= 0; i--)
        for(int j = N - 1; j >= 0; j--)
            for(int k = 0; k < 2; k++)
            {
                int aux = a[i][j], cnt1 = 0;
                if(aux == 0)
                {
                    cnt1 = 1;
                    pos = {i, j};
                }
                else
                {
                    while(aux%(k?5:2) == 0)
                    {
                        aux /= (k?5:2);
                        cnt1++;
                    }
                }
                cnt[k][i][j] = cnt1;
                if(i == N - 1 && j == N - 1)
                    DP[k][i][j] = cnt1;
                else
                    DP[k][i][j] = min(DP[k][i + 1][j], DP[k][i][j + 1]) + cnt1;
            }

    int minim;
    if(DP[0][0][0] < DP[1][0][0])
        minim = 0;
    else
        minim = 1;
    
    if(pos.first != -1 && DP[minim][0][0] > 1)
    {
        cout << "1\n";
        for(int i = 0; i < pos.first; i++)
            cout << "D";
        for(int i = 0; i < N - 1; i++)
            cout << "R";
        for(int i = pos.first; i < N - 1; i++)
            cout << "D";
        return 0;
    }

    cout << DP[minim][0][0] << "\n";

    int x = 0, y = 0;
    while(x != N - 1 || y != N - 1)
    {
        dbg(x, y);
        if(DP[minim][x + 1][y] < DP[minim][x][y + 1])
        {
            cout << "D";
            x++;
        }
        else
        {
            cout << "R";
            y++;
        }
    }
    cout << "\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

