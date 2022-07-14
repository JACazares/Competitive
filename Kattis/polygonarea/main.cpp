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

struct Point
{
	ld x, y;
	Point(ld x = 0, ld y = 0) : x(x), y(y) {}

	friend std::istream& operator>>(std::istream& out, const Point& _x);
	friend std::ostream& operator<<(std::ostream& out, const Point& _x);

	bool operator ==(const Point& _x) const {
		return (x == _x.x && y == _x.y);
	}

	Point operator +(const Point& _x) const {
		return Point(x + _x.x, y + _x.y);
	}
	Point operator -(const Point& _x) const {
		return Point(x - _x.x, y - _x.y);
	}
	Point operator *(const ld& _x) const {
		return Point(x*_x, y*_x);
	}
};
istream& operator>>(istream& in, Point& _x) { in >> _x.x >> _x.y;return in; }
ostream& operator<<(ostream& out, const Point& _x) { out.setf(ios::fixed); out.precision(2); out << _x.x << " " << _x.y; return out; }

struct Line
{
	Point a, v;

	Line(Point a, Point v) : a(a), v(v) {}
	friend std::ostream& operator<<(std::ostream& out, const Line& _x);
};
ostream& operator<<(ostream& out, const Line& _x) { out << _x.a << " " << _x.v; return out; }

ld dot(Point _x, Point _y) { return _x.x*_y.x + _x.y*_y.y; }
ld cross(Point _x, Point _y) { return _x.x*_y.y - _x.y*_y.x; }
ld dist2(Point _x) { return dot(_x, _x); }
ld dist(Point _x) { return sqrt(dist2(_x)); }

Point ZERO = Point(0, 0);

const int MAXN = (int)1e3 + 5;
Point p[MAXN];

void solve(int N)
{
	for(int i = 0; i < N; i++)
		cin >> p[i];
	
	ld area = 0;
	for(int i = 0; i < N; i++)
		area += cross(p[i], p[(i+1)%N]);
	
	cout.setf(ios::fixed);
	cout.precision(1);
	if(area > 0)
		cout << "CCW " << area/2 << "\n";
	else
		cout << "CW " << -area/2 << "\n";
}

int main()
{
	optimizeIO();
	int N;
	cin >> N;
	while(N != 0)
	{
		solve(N);
		cin >> N;
	}
	return 0;
}
