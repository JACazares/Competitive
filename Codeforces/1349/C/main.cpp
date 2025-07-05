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

const int MAXN = 1005;
const ll INF = (1LL << 62LL);
int N, M, T, vis[MAXN][MAXN];
ll disc[MAXN][MAXN];
char a[MAXN][MAXN];
queue<pair<pii, int>> Q;

bool valid(int i, int j)
{
    if(i <= 0 || N < i)
        return false;
    if(j <= 0 || M < j)
        return false;
    if(vis[i][j])
        return false;
    return true;
}

void floodfill(int i, int j)
{
    disc[i][j] = 0;
    Q.push(mp(mp(i, j), 0));
    for(int k = 0; k < 4; k++)
        if(valid(i + dx[k], j + dy[k]) && a[i][j] == a[i + dx[k]][j + dy[k]])
        {
            vis[i + dx[k]][j + dy[k]] = 1;
            floodfill(i + dx[k], j + dy[k]);
        }
}

void checklonely(int i, int j)
{
    int distinct = 0, tot = 0;
    for(int k = 0; k < 4; k++)
        if(valid(i + dx[k], j + dy[k]))
        {
            if(a[i][j] != a[i + dx[k]][j + dy[k]])
                distinct++;
            tot++;
        }
    if(distinct == tot)
        return;
    vis[i][j] = 1;
    floodfill(i, j);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        {
            cin >> a[i][j];
            disc[i][j] = INF;
        }
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(!vis[i][j])
                checklonely(i, j);
    while(!Q.empty())
    {
        auto pos = Q.front();
        Q.pop();
        
        int i = pos.first.first, j = pos.first.second, tim = pos.second;
        for(int k = 0; k < 4; k++)
            if(valid(i + dx[k], j + dy[k]))
            {
                vis[i + dx[k]][j + dy[k]] = 1;
                disc[i + dx[k]][j + dy[k]] = tim + 1;
                Q.push(mp(mp(i + dx[k], j + dy[k]), tim + 1));
            }
    }

    /*for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            cout << disc[i][j] << " ";
        cout << "\n";
    }*/
    
    for(int i = 0; i < T; i++)
    {
        int x, y;
        ll p;
        cin >> x >> y >> p;
        if(p < disc[x][y])
            cout << a[x][y] << "\n";
        else
        {
            if((p - disc[x][y]) % 2 == 0)
                cout << a[x][y] << "\n";
            else
            {
                if(a[x][y] == '0')
                    cout << "1\n";
                else
                    cout << "0\n";
            }
        }
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

