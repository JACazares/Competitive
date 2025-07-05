#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second

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
#define openFiles() 0
#else
#define dbg(...) 0
#define optimizeIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define openFiles() freopen("file.in", "r", stdin); freopen("file.out", "w", stdout)
#endif

int N;
vpi primes;

void solve()
{
    cin >> N;
    int aux = N;
    primes.clear();
    for(int i = 2; i*i <= N; i++)
    {
        if(N % i == 0)
        {
            int cnt = 0;
            while(N % i == 0)
            {
                N /= i;
                cnt++;
            }
            primes.pb({i, cnt});
        }
    }
    if(N != 1)
        primes.pb({N, 1});
    N = aux;

    sort(all(primes));
    dbg(primes);
    
    if(primes.size() == 1)
    {
        for(int i = 2; i*i <= N; i++)
            if(N % i == 0)
            {
                cout << i << " ";
                if(i != N/i)
                    cout << N/i << " ";
            }
        cout << N << "\n0\n";
        return;
    }
    if(primes.size() == 2)
    {
        if(primes[0].second == 1 && primes[1].second == 1)
        {
            for(int i = 2; i*i <= N; i++)
                if(N % i == 0)
                {
                    cout << i << " ";
                    if(i != N/i)
                        cout << N/i << " ";
                }
            cout << N << "\n1\n";
            return;
        }
        else
        {
            vi a{primes[0].first, N, primes[1].first, primes[0].first*primes[1].first};
            map<int, int> vis;
            for(int k = 0; k < 4; k++)
                vis[a[k]] = 1;
            for(int k = 0; k < 4; k++)
            {
                cout << a[k] << " ";
                for(int i = 2; i*i <= N; i++)
                {
                    if(N % i == 0 && i % a[k] == 0 && !vis[i])
                    {
                        cout << i << " ";
                        vis[i] = 1;
                    }
                    if(N % i == 0 && (N/i) % a[k] == 0 && !vis[N/i])
                    {
                        cout << N/i << " ";
                        vis[N/i] = 1;
                    }
                }
            }
            cout << "\n0\n";
            return;
        }
    }
    int last = primes[primes.size() - 1].first;
    vi ans;
    map<int, int> vis;

    for(int k = 0; k < primes.size(); k++)
    {
        vis[last*primes[k].first] = 1;
        last = primes[k].first;
    }

    for(int k = 0; k < primes.size(); k++)
    {
        cout << (last*primes[k].first) << " ";
        vis[last*primes[k].first] = 1;
        for(int i = 2; i*i <= N; i++)
        {
            if(N % i == 0 && i % primes[k].first == 0 && !vis[i])
            {
                cout << i << " ";
                vis[i] = 1;
            }
            if(N % i == 0 && (N/i) % primes[k].first == 0 && !vis[N/i])
            {
                cout << N/i << " ";
                vis[N/i] = 1;
            }
        }
        last = primes[k].first;
    }
    cout << N << "\n0\n";
}

int main ()
{
    optimizeIO();
    //openFiles();
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
