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

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int i, int j, int color, const vector<vector<char>>& a, vector<vi>& vis, const int N, const int M)
{
	for(int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];

		if(new_i < 0 || N <= new_i || new_j < 0 || M <= new_j)
			continue;
		
		if(vis[new_i][new_j] || a[new_i][new_j] == '.')
			continue;

		vis[new_i][new_j] = color;
		dfs(new_i, new_j, color, a, vis, N, M);
	}
}

void solve()
{
	int N, M;
	cin >> N >> M;
	vector<vector<char>> a(N, vector<char>(M, '.'));
	vector<vi> vis(N, vi(M, 0));
	int color = 1;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> a[i][j];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(!vis[i][j] && a[i][j] == '#')
			{
				vis[i][j] = color;
				dfs(i, j, color, a, vis, N, M);
				color++;
			}

	vi component_sizes(color, 0);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(vis[i][j] > 0)
				component_sizes[vis[i][j]]++;
	
			
	int ans = 0;
	// Fill in row i
	for(int i = 0; i < N; i++)
	{
		int total_size = 0;
		unordered_map<int, bool> ct;

		for(int j = 0; j < M; j++)
		{
			if(a[i][j] == '.')
				total_size++;

			if(vis[i][j] && !ct[vis[i][j]])
			{
				total_size += component_sizes[vis[i][j]];
				ct[vis[i][j]] = 1;
			}

			if(i - 1 >= 0 && vis[i - 1][j] && !ct[vis[i - 1][j]])
			{
				total_size += component_sizes[vis[i - 1][j]];
				ct[vis[i - 1][j]] = 1;
			}

			if(i + 1 < N && vis[i + 1][j] && !ct[vis[i + 1][j]])
			{
				total_size += component_sizes[vis[i + 1][j]];
				ct[vis[i + 1][j]] = 1;
			}
		}

		ans = max(ans, total_size);
	}

	// Fill in col j
	for(int j = 0; j < M; j++)
	{
		int total_size = 0;
		unordered_map<int, bool> ct;

		for(int i = 0; i < N; i++)
		{
			if(a[i][j] == '.')
				total_size++;

			if(vis[i][j] && !ct[vis[i][j]])
			{
				total_size += component_sizes[vis[i][j]];
				ct[vis[i][j]] = 1;
			}

			if(j - 1 >= 0 && vis[i][j-1] && !ct[vis[i][j - 1]])
			{
				total_size += component_sizes[vis[i][j - 1]];
				ct[vis[i][j - 1]] = 1;
			}

			if(j + 1 < M && vis[i][j+1] && !ct[vis[i][j + 1]])
			{
				total_size += component_sizes[vis[i][j + 1]];
				ct[vis[i][j + 1]] = 1;
			}
		}

		ans = max(ans, total_size);
	}

	cout << ans << "\n";
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}


