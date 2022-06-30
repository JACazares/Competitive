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

const int MAXN = (int)2e5 + 5;
int N, a[2], c, d;
int tot[2], num[2], blocked[MAXN];
string s, S;

bool solve()
{
	cin >> a[0] >> a[1] >> c >> d;
	cin >> s;
	N = s.length();
	
	tot[0] = a[0] + c + d;
	tot[1] = a[1] + c + d;
	
	num[0] = 0;
	num[1] = 0;
	for(auto i : s)
		num[i - 'A']++;
	if(tot[0] != num[0] || tot[1] != num[1])
		return false;

	if(N == 1)
		return true;
	
	for(int i = 0; i < N; i++)
		blocked[i] = 0;
		
	if(s[0] == s[1])
	{
		blocked[0] = 1;
		tot[s[0] - 'A']--;
		num[s[0] - 'A']--;
		a[s[0] - 'A']--;
	}
	if(s[N - 2] == S[N - 1])
	{
		blocked[N - 1] = 1;
		tot[s[N - 1] - 'A']--;
		num[s[N - 1] - 'A']--;
		a[s[N - 1] - 'A']--;
	}
	for(int i = 1; i < N - 1; i++)
		if(s[i] == s[i - 1] && s[i] == s[i + 1])
		{
			blocked[i] = 1;
			tot[s[i] - 'A']--;
			num[s[i] - 'A']--;
			a[s[i] - 'A']--;
		}
	
	if(a[0] < 0 || a[1] < 0)
		return false;
	
	S = "";
	for(int i = 0; i < N; i++)
		if(!blocked[i])
			S += s[i];
	N = S.length();
	
	int len = 0;
	string aux = "";
	
	aux += S[0];
	len = 1;
	vector<pair<int, string>> even, odd;
	even.clear();
	odd.clear();
	for(int i = 1; i < N; i++)
	{
		if(S[i] == S[i - 1])
		{
			if(len % 2 == 0)
				even.pb({-len, aux});
			else
				odd.pb({-len, aux});
			aux = "";
			len = 0;
		}
		aux += S[i];
		len++;
	}
	if(len % 2 == 0)
		even.pb({-len, aux});
	else
		odd.pb({-len, aux});
	
	sort(all(even));
	sort(all(odd));
	
	for(auto i : odd)
		a[i.second[0] - 'A']--;

	if(a[0] < 0 || a[1] < 0)
		return false;
	
	dbg(even);
	dbg(odd);
	
	int needC = 0, needD = 0;
	for(auto i : even)
	{
		if(i.second[0] == 'A')
			needC += (-i.first/2);
		else if(i.second[0] == 'B')
			needD += (-i.first/2);
	}
	dbg(needC, needD, c, d, a[0], a[1]);
	
	for(auto i : even)
	{
		if(needC <= c)
			break;
		if(i.second[0] == 'A')
		{
			needC -= (-i.first/2);
			a[0]--;
			a[1]--;
		}
	}
	
	for(auto i : even)
	{
		if(needD <= d)
			break;
		if(i.second[0] == 'B')
		{
			needD -= (-i.first/2);
			a[0]--;
			a[1]--;
		}
	}
	
	if(a[0] < 0 || a[1] < 0 || needC > c || needD > d)
		return false;
	return true;
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	while(T--)
		cout << (solve() ? "YES" : "NO") << "\n";
	return 0;
}
