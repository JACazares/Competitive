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

const int MAXN = 1e5 + 5;
int N, dead[MAXN], nxtA[MAXN], nxtB[MAXN], nxtC[MAXN];
string s, t;

void solve()
{
	cin >> N;
	for(int i = 0; i <= N; i++)
		dead[i] = 0;
	cin >> s >> t;
	
	nxtA[N] = N;
	nxtB[N] = N;
	nxtC[N] = N;
	for(int i = N - 1; i >= 0; i--)
	{
		nxtA[i] = nxtA[i + 1];
		nxtB[i] = nxtB[i + 1];
		nxtC[i] = nxtC[i + 1];
		
		if(s[i] == 'a')
			nxtA[i] = i;
		if(s[i] == 'b')
			nxtB[i] = i;
		if(s[i] == 'c')
			nxtC[i] = i;
	}
	
	bool ans = 1;
	int l = 0;
	for(int i = 0; i < N; i++)
	{
		while(dead[l])
			l++;
		dbg(i, l);
		if(t[i] == s[l])
		{
			l++;
			continue;
		}

			
		if(t[i] == 'a')
		{
			ans = 0;
			break;
		}
		else if(t[i] == 'b')
		{
			while(dead[nxtB[l]])
				nxtB[l] = nxtB[nxtB[l] + 1];
				
			if(nxtA[l] < nxtB[l] && nxtB[l] < nxtC[l])
				dead[nxtB[l]] = 1;
			else
			{
				ans = 0;
				break;
			}
		}
		else if(t[i] == 'c')
		{
			while(dead[nxtC[l]])
				nxtC[l] = nxtC[nxtC[l] + 1];

			if(nxtB[l] < nxtC[l] && nxtC[l] < nxtA[l])
				dead[nxtC[l]] = 1;
			else
			{
				ans = 0;
				break;
			}
		}
	}
	
	cout << (ans ? "YES" : "NO") << "\n";
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
