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

const ll MOD = 1007;

ll binexp(ll b, ll e)
{
	if(e == 0)
		return 1;
	else if(e == 1)
		return b;
	else if(e&1)
		return (b*binexp(b, e-1))%MOD;
	else
	{
		ll x = binexp(b, e/2);
		return (x*x)%MOD;
	}
}

ll inv(ll x) { return binexp(x, MOD - 2); }

void solve()
{
	int N;
	cin >> N;
	vl fall(N + 1), stay(N + 1);
	for(int i = 1; i <= N; i++)
	{
		ll p, q;
		cin >> p >> q;
		ll g = gcd(p, q);
		p /= g;
		q /= g;

		fall[i] = (p * inv(q)) % MOD;
		stay[i] = ((q - p) * inv(q)) % MOD;
	}
	
	vector<vi> Graph(N + 1);
	vpi edges;
	for(int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
		edges.pb({u, v});
	}

	// Calculate probability that all neighbors of v fall
	vl all_fall_prob(N + 1, 0);
	for(int v = 1; v <= N; v++)
	{
		all_fall_prob[v] = stay[v];
		for(auto x : Graph[v])
		{
			all_fall_prob[v] *= fall[x];
			all_fall_prob[v] %= MOD;
		}
	}

	dbg(all_fall_prob);

	// Calculate individual leaf probability
	vl leaf_prob(N + 1);
	for(int v = 1; v <= N; v++)
	{
		ll single_stay = 0;
		for(auto x : Graph[v])
		{
			// dbg(v, x, (stay[x]*inv(fall[x]))%MOD);
			single_stay += (stay[x]*inv(fall[x]))%MOD;
			single_stay %= MOD;
		}
		// dbg(v, single_stay);
		leaf_prob[v] = (all_fall_prob[v]*single_stay)%MOD;
	}

	dbg(leaf_prob);

	ll ans = 0;
	// Case 1: u -- v
	for(auto [u, v] : edges)
	{
		ll prob = (stay[u]*stay[v])%MOD;
		for(auto x : Graph[u])
		{
			if(x == v)
				continue;
			prob *= fall[x];
			prob %= MOD;
		}
		for(auto x : Graph[v])
		{
			if(x == u)
				continue;
			prob *= fall[x];
			prob %= MOD;
		}

		// dbg(u, v, prob);

		ans += prob;
		ans %= MOD;
	}

	// Case 2: u -- x -- v
	for(int x = 1; x <= N; x++)
	{
		// dbg(x);
		// Case 2a: x stays, all other neighbors fall
		ll prob_x_stays = 0;
		ll sum_all_fall = 0;
		for(auto v : Graph[x])
		{
			// sum_all_fall is the combined probability for all neighbors x becoming isolated with everything, except for
			// x, which we don't care about until the next loop
			sum_all_fall += (all_fall_prob[v]*inv(fall[x]))%MOD;
			sum_all_fall %= MOD;
		}

		for(auto v : Graph[x])
		{
			// v_stays is the probability that all neighbors of v fall except for x
			ll v_stays = (all_fall_prob[v] * inv(fall[x]))%MOD;
			v_stays *= stay[x];
			v_stays %= MOD;

			// v_stays_total combines the probability of v and one other neighbors becoming leaves, by way of keeping x
			ll v_stays_total = ((sum_all_fall - (all_fall_prob[v]*inv(fall[x]))%MOD) + MOD)%MOD;
			v_stays_total *= v_stays;
			v_stays_total %= MOD;

			prob_x_stays += v_stays_total;
			// dbg(v, v_stays_total);
			prob_x_stays %= MOD;
		}

		ans += (prob_x_stays * inv(2))%MOD;
		ans %= MOD;

		// Case 2b: x falls, one other neighbor stays
		ll prob_x_falls = 0;
		ll sum_x_falls = 0;
		for(auto v : Graph[x])
		{
			sum_x_falls += ((leaf_prob[v] - (((all_fall_prob[v]*stay[x])%MOD)*inv(fall[x]))%MOD) + MOD)%MOD;
			sum_x_falls %= MOD;
		}

		for(auto v : Graph[x])
		{
			ll x_falls = ((leaf_prob[v] - (((all_fall_prob[v]*stay[x])%MOD)*inv(fall[x]))%MOD) + MOD)%MOD;
			ll x_falls_total = (sum_x_falls * (((sum_x_falls - x_falls)%MOD + MOD)%MOD))%MOD;;
			// dbg(v, x_falls_total);
			prob_x_falls += x_falls_total;
			prob_x_falls %= MOD;
		}

		ans += (prob_x_falls * inv(2))%MOD;
		ans %= MOD;
	}

	// Case 3: u, v independent
	ll prob_u_v_indep = 0;
	ll sum_leaf_prob = 0;
	for(int v = 1; v <= N; v++)
	{
		sum_leaf_prob += leaf_prob[v];
		sum_leaf_prob %= MOD;
	}
	dbg(sum_leaf_prob);

	vl sum_neighbor_leaf(N + 1);
	for(int v = 1; v <= N; v++)
	{
		sum_neighbor_leaf[v] = leaf_prob[v];
		for(auto x : Graph[v])
		{
			sum_neighbor_leaf[v] += leaf_prob[x];
			sum_neighbor_leaf[v] %= MOD;
		}
	}
	dbg(sum_neighbor_leaf);

	for(int v = 1; v <= N; v++)
	{
		ll sum_dependent_nodes = leaf_prob[v];
		for(auto x : Graph[v])
		{
			sum_dependent_nodes += ((sum_neighbor_leaf[x] - leaf_prob[v])%MOD + MOD)%MOD;
			sum_dependent_nodes %= MOD;
		}
		dbg(v, sum_dependent_nodes);

		prob_u_v_indep += (leaf_prob[v] * (((sum_leaf_prob - sum_dependent_nodes)%MOD + MOD)%MOD))%MOD;
		prob_u_v_indep %= MOD;
	}

	ans += (prob_u_v_indep * inv(2))%MOD;
	ans %= MOD;

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

