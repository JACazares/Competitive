#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second
 
int pct(int x) { return __builtin_popcount((unsigned int)x); }
 
// TO_STRING, credits: Benq
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[(unsigned long)i]);
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
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h);
    if (sizeof...(t))
        cerr << ", ";
	DBG(t...);
}
 
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define optimizeIO() 0
#else
#define dbg(...) 0
#define optimizeIO() ios_base::sync_with_stdio(false); cin.tie(nullptr)
#endif

const int MAXN = 45;
int N, K, A[MAXN][MAXN], DP[MAXN][MAXN][MAXN*MAXN];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool valid(int i, int j)
{
	if(i < 0 || i >= N)
		return false;
	if(j < 0 || j >= N)
		return false;
	return true;
}

void solve()
{
	cin >> N >> K;
	int curr_row = 0, curr_col = 0;
	int cnt = 0, cap = (N - 1) * 4, actual_N = N;;
	for(int i = 1; i < N*N; i++)
	{
		A[curr_row][curr_col] = i;
		
		if(i - cnt == cap)
		{
			actual_N -= 2;
			cnt += cap;
			cap += (actual_N - 1) * 4;
		}
			
		if(actual_N > 1)
		{
			int section = (i - cnt - 1) / (actual_N - 1);
			if(section == 0)
				curr_col++;
			else if(section == 1)
				curr_row++;
			else if(section == 2)
				curr_col--;
			else if(section == 3)
				curr_row--;
		}
	}
	A[N/2][N/2] = N*N;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k <= K; k++)
				DP[i][j][k] = 0;
				
	DP[N/2][N/2][0] = 1;
	
	for(int k = 1; k <= K; k++)
	{
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int s = 0; s < 4; s++)
					if(valid(i + dx[s], j + dy[s]) && A[i + dx[s]][j + dy[s]] > A[i][j])
						DP[i][j][k] = max(DP[i][j][k], DP[i + dx[s]][j + dy[s]][k - 1]);
	}
	
	if(DP[0][0][K] == 0)
		cout << "IMPOSSIBLE\n";
	else
	{
		int curr_i = 0, curr_j = 0;
		vi pos;
		pos.clear();
		for(int k = K; k > 0; k--)
		{
			pos.pb(A[curr_i][curr_j]);
			for(int s = 0; s < 4; s++)
			{
				if(valid(curr_i + dx[s], curr_j + dy[s])
					&& A[curr_i + dx[s]][curr_j + dy[s]] > A[curr_i][curr_j]
					&& DP[curr_i + dx[s]][curr_j + dy[s]][k - 1] == 1)
				{
					curr_i += dx[s], curr_j += dy[s];
					break;
				}
			}
		}
		pos.pb(A[curr_i][curr_j]);
		
		int ans = 0;
		for(int i = 1; i < sz(pos); i++)
			if(pos[i] != pos[i - 1] + 1)
				ans++;
		cout << ans << "\n";
		for(int i = 1; i < sz(pos); i++)
			if(pos[i] != pos[i - 1] + 1)
				cout << pos[i - 1] << " " << pos[i] << "\n";
	}
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
