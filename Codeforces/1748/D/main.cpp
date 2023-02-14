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

const int MAXL = 30, MAXX = 60;
int a, b;
ll d;

void solve()
{
	vpi common, mA, mB;
	common.clear();
	mA.clear();
	mB.clear();
	
	cin >> a >> b >> d;
	int ar = a % d, br = b % d;
	for(int i = 0; i < MAXL; i++)
	{
		int a_on = (a & (1 << i));
		int b_on = (b & (1 << i));
		int m_bit = (1 << i) % d;
		
		if(!a_on && !b_on)
			common.pb({m_bit, i});
		else if(!a_on)
			mA.pb({m_bit, i});
		else if(!b_on)
			mB.pb({m_bit, i});
	}
	for(int i = MAXL; i < MAXX; i++)
		common.pb({(1LL << i) % d, i});
	
	dbg(common);
	dbg(mA);
	dbg(mB);
	
	if(sz(mA) <= 15)
	{
		map<int, vi> sums;
		for(int i = 0; i < (1 << sz(mA)); i++)
		{
			ll sum = 0;
			vi recon;
			recon.clear();
			for(int k = 0; k < sz(mA); k++)
				if(i & (1 << k))
				{
					sum += mA[k].first;
					sum %= d;
					recon.pb(mA[k].second);
				}
			
			sums[sum] = recon;
		}
		
		dbg(sums);
		
		set<int> resA, resB;
		for(auto x : sums)
		{
			int auxa = ((-ar - x.first)%d + d)%d;
			int auxb = ((x.first + ar - br)%d + d)%d;
			
			resA.insert(auxa);
			resB.insert(auxb);
		}
		resA.insert(0);
		resB.insert(0);
		dbg(resA);
		dbg(resB);
		
		map<int, int> modA, modB;
		map<int, vi> reconA, reconB;
		
		modA[0] = 1;
		reconA[0] = {};
		for(int i = 0; i < sz(common); i++)
		{
			map<int, int> tmp;
			tmp.clear();
			for(auto k : resA)
			{
				if(!modA[k])
					continue;
					
				tmp[k] = 1;
				int nxt = (k + common[i].first) % d;
				if(resA.contains(nxt))
				{
					if(modA[nxt] == 0)
					{
						reconA[nxt] = {};
						for(auto j : reconA[k])
							reconA[nxt].pb(j);
						reconA[nxt].pb(common[i].second);
					}
					tmp[nxt] = 1;
				}
			}
			swap(tmp, modA);
			dbg(modA);
		}
		
		modB[0] = 1;
		reconB[0] = {};
		for(int i = 0; i < sz(mB); i++)
		{
			map<int, int> tmp;
			tmp.clear();
			for(auto k : resB)
			{
				if(!modB[k])
					continue;
					
				tmp[k] = 1;
				int nxt = (k + mB[i].first) % d;
				if(modB[nxt] == 0)
				{
					reconB[nxt] = {};
					for(auto j : reconB[k])
						reconB[nxt].pb(j);
					reconB[nxt].pb(mB[i].second);
				}
				tmp[nxt] = 1;
			}
			swap(tmp, modB);
		}
		
		for(auto x : sums)
		{
			int auxa = ((-ar - x.first)%d + d)%d;
			int auxb = ((x.first + ar - br)%d + d)%d;
			
			if(modA[auxa] && modB[auxb])
			{
				ll ans = 0;
				for(auto i : x.second)
					ans |= (1LL << i);
				for(auto i : reconA[auxa])
					ans |= (1LL << i);
				for(auto i : reconB[auxb])
					ans |= (1LL << i);
				cout << ans << "\n";
				return;
			}
		}
		cout << "-1\n";
		
	}
	else if(sz(mB) <= 15)
	{
		map<int, vi> sums;
		for(int i = 0; i < (1 << sz(mB)); i++)
		{
			ll sum = 0;
			vi recon;
			recon.clear();
			for(int k = 0; k < sz(mB); k++)
				if(i & (1 << k))
				{
					sum += mB[k].first;
					sum %= d;
					recon.pb(mB[k].second);
				}
			
			sums[sum] = recon;
		}
		
		set<int> resA, resB;
		for(auto x : sums)
		{
			int auxa = ((-br - x.first)%d + d)%d;
			int auxb = ((x.first + br - ar)%d + d)%d;
			
			resA.insert(auxa);
			resB.insert(auxb);
		}
		resA.insert(0);
		resB.insert(0);
		
		map<int, int> modA, modB;
		map<int, vi> reconA, reconB;
		
		modA[0] = 1;
		reconA[0] = {};
		for(int i = 0; i < sz(common); i++)
		{
			map<int, int> tmp;
			tmp.clear();
			for(auto k : resA)
			{
				if(!modA[k])
					continue;
					
				tmp[k] = 1;
				int nxt = (k + common[i].first) % d;
				if(modA[nxt] == 0)
				{
					reconA[nxt] = {};
					for(auto j : reconA[k])
						reconA[nxt].pb(j);
					reconA[nxt].pb(common[i].second);
				}
				tmp[nxt] = 1;
			}
			swap(tmp, modA);
		}
		
		modB[0] = 1;
		reconB[0] = {};
		for(int i = 0; i < sz(mA); i++)
		{
			map<int, int> tmp;
			tmp.clear();
			for(auto k : resB)
			{
				if(!modB[k])
					continue;
					
				tmp[k] = 1;
				int nxt = (k + mA[i].first) % d;
				if(modB[nxt] == 0)
				{
					reconB[nxt] = {};
					for(auto j : reconB[k])
						reconB[nxt].pb(j);
					reconB[nxt].pb(mA[i].second);
				}
				tmp[nxt] = 1;
			}
			swap(tmp, modB);
		}
		
		for(auto x : sums)
		{
			int auxa = ((-br - x.first)%d + d)%d;
			int auxb = ((x.first + br - ar)%d + d)%d;
			
			if(modA[auxa] && modB[auxb])
			{
				ll ans = 0;
				for(auto i : x.second)
					ans |= (1LL << i);
				for(auto i : reconA[auxa])
					ans |= (1LL << i);
				for(auto i : reconB[auxb])
					ans |= (1LL << i);
				cout << ans << "\n";
				return;
			}
		}
		cout << "-1\n";
	}
	
}

int main()
{
	optimizeIO();
	int T = 1;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
