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

int main()
{
	optimizeIO();
	int p4, p7, p47, p74;
	cin >> p4 >> p7 >> p47 >> p74;

	if(p4 < p47 || p4 < p74 || p7 < p47 || p7 < p74 || abs(p47 - p74) > 1)
	{
		cout << "-1\n";
		return 0;
	}

	if(p47 == p74)
	{
		string start = "", mid = "", end = "";
		if(p4 - p47 - 1 < 0)
		{
			if(p7 - p47 - 1 < 0)
			{
				cout << "-1\n";
				return 0;
			}

			for(int i = 0; i < p47; i++)
				mid += "47";
			
			start = "7";
			for(int i = 0; i < p4 - p47; i++)
				start += "4";

			for(int i = 0; i < p7 - p47 - 1; i++)
				end += "7";
			cout << start + mid + end << "\n";
			return 0;
		}

		for(int i = 0; i < p47; i++)
			mid += "47";
		
		for(int i = 0; i < p4 - p47 - 1; i++)
			start += "4";

		for(int i = 0; i < p7 - p47; i++)
			end += "7";
		end += "4";

		cout << start + mid + end << "\n";
	}
	else if(p47 == p74 + 1)
	{

		string start = "", mid = "", end = "";
		for(int i = 0; i < p47; i++)
			mid += "47";
		
		for(int i = 0; i < p4 - p47; i++)
			start += "4";

		for(int i = 0; i < p7 - p47; i++)
			end += "7";

		cout << start + mid + end << "\n";
	}
	else if(p74 == p47 + 1)
	{
		if(p74 == 1)
		{
			for(int i = 0; i < p7; i++)
				cout << "7";
			for(int i = 0; i < p4; i++)
				cout << "4";
			return 0;
		}
		string start = "", mid = "", end = "";
		start = "74";
		for(int i = 0; i < p4 - p74; i++)
			start += "4";

		for(int i = 0; i < p74 - 2; i++)
			mid += "74";
		
		for(int i = 0; i < p7 - p74 + 1; i++)
			end += "7";
		end += "4";


		cout << start + mid + end << "\n";
	}
	return 0;
}


