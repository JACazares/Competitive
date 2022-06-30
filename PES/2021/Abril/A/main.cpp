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
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = (int)1e5 + 5, MAXA = (int)1e6 + 5;
const ll INF = (1LL << 62LL);
int N;
ll a[MAXN], c[MAXN];
ll pre[MAXN], DP[MAXN];

typedef complex<ll> point;
#define x real
#define y imag

ll dot(point _a, point _b) {
    return (conj(_a) * _b).x();
}

ll f(point _a, ll x) {
    return dot(_a, {x, 1});
}

point line[4 * MAXA];

void init(int v = 1, int l = 0, int r = MAXA)
{
    int m = (l + r) / 2;
	line[v] = {0, INF};
    if(r - l == 1) {
        return;
    }
	init(2 * v, l, m);
	init(2 * v + 1, m, r);
}

void add_line(point nw, int v = 1, int l = 0, int r = MAXA) {
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if(mid) {
        swap(line[v], nw);
    }
    if(r - l == 1) {
        return;
    } else if(lef != mid) {
        add_line(nw, 2 * v, l, m);
    } else {
        add_line(nw, 2 * v + 1, m, r);
    }
}

ll get(ll x, int v = 1, int l = 0, int r = MAXA) {
    int m = (l + r) / 2;
    if(r - l == 1) {
        return f(line[v], x);
    } else if(x < m) {
        return min(f(line[v], x), get(x, 2 * v, l, m));
    } else {
        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
    }
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	for(int i = 1; i <= N; i++)
	{
		cin >> c[i];
		pre[i] = pre[i - 1] + c[i];
	}
	
	ll m = -2*a[N];
	ll b = pre[N - 1] + a[N]*a[N];
	init();
	add_line({m, b});
	for(int i = N - 1; i >= 1; i--)
	{
		DP[i] = get(a[i]) + a[i]*a[i] - pre[i];
		m = -2*a[i];
		b = DP[i] + pre[i - 1] + a[i]*a[i];
		add_line({m, b});
	}
	cout << DP[1] << "\n";
	return 0;
}
