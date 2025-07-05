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

void solve()
{
	int N;
	cin >> N;
	vi x[3];
	for(int k = 0; k < 3; k++)
	{
		x[k].resize(N, 0);
		for(int i = 0; i < N; i++)
			cin >> x[k][i];
	}

	ll tot = 0;
	for(int i = 0; i < N; i++)
		tot += x[0][i];
	
	ll minim = tot/3 + ((tot%3) != 0); // ceil(tot/3), where tot is an integer.

	vi r_end[3];
	for(int k = 0; k < 3; k++)
	{
		ll curr_sum = 0;
		int rpnt = 0;

		r_end[k].resize(N, N);
		for(int i = 0; i < N; i++)
		{
			while(rpnt < N && curr_sum + x[k][rpnt] < minim)
				curr_sum += x[k][rpnt++];
			
			r_end[k][i] = rpnt;
			
			if(rpnt > i)
				curr_sum -= x[k][i];

			if(rpnt == i)
				rpnt++;
		}
	}

	// dbg(r_end[0]);
	// dbg(r_end[1]);
	// dbg(r_end[2]);

	vi perm = {0, 1, 2};
	do
	{
		int curr_left = 0;
		int curr_right = 0;
		
		int ans = 1;
		vi l(3, 0), r(3, 0);
		for(int k = 0; k < 3; k++)
		{
			if(curr_left >= N)
			{
				ans = 0;
				break;
			}

			curr_right = r_end[perm[k]][curr_left];
			if(curr_right == N)
			{
				ans = 0;
				break;
			}

			l[perm[k]] = curr_left;
			r[perm[k]] = curr_right;
			
			curr_left = curr_right + 1;
		}

		if(ans)
		{
			for(int k = 0; k < 3; k++)
				cout << l[k] + 1 << " " << r[k] + 1 << " ";
			cout << "\n";
			return;
		}

	} while(next_permutation(all(perm)));

	cout << "-1\n";
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
