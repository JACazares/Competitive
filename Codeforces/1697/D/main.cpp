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

const int MAXN = 1e3 + 5;
int N, x[MAXN], p[MAXN], vis[MAXN];
char let[MAXN];
vi valid;

int look(int node)
{
	if(p[node] == node)
		return node;
	return p[node] = look(p[node]);
}

void join(int a, int b)
{
	p[look(b)] = look(a);
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		p[i] = i;

	for(int i = 1; i <= N; i++)
	{
		cout << "? 2 " << 1 << " " << i << endl;
		
		cin >> x[i];
		if(x[i] == 0)
			return 0;
		
		if(x[i] == x[i - 1])
		{
			int s = 0, e = valid.size() - 1, mid, val, ans = 0;
			while(s <= e)
			{
				mid = (s + e)/2;
				cout << "? 2 " << valid[mid] << " " << i << endl;
				
				cin >> val;
				if(val == 0)
					return 0;
				
				if(val == x[i] - mid)
				{
					ans = mid;
					s = mid + 1;
				}
				else
					e = mid - 1;
			}
			
			join(valid[ans], i);
			erase(valid, valid[ans]);
		}
		valid.pb(i);
	}
	
	for(int i = 1; i <= N; i++)
		if(!vis[look(i)])
		{
			vis[look(i)] = 1;
			cout << "? 1 " << look(i) << endl;
			
			cin >> let[look(i)];
			if(let[look(i)] == '0')
				return 0;
		}
	
	cout << "! ";
	for(int i = 1; i <= N; i++)
		cout << let[look(i)];
	cout << endl;
	return 0;
}
