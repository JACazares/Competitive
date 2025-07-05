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

#define mp make_pair
#define sz(x) (int)x.size()
#define pb push_back

int pct(int x) { return __builtin_popcount(x); }
template<class T> T ceil(T a, T b) {
    return ((a)/(b) + ((a)%(b) ? 1 : 0)); }
template<class T> T floor(T a, T b) {
    return ((a)/(b)); }

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
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

//point
struct Point
{
    ld x, y;

    Point(ld x1, ld y1)
    {
        x = x1;
        y = y1;
    }
    
    Point()
    {
        Point(0, 0);
    }

    Point operator +(const Point& _x) const
    {
        return Point(x + _x.x, y + _x.y);
    }
    Point operator -(const Point& _x) const
    {
        return Point(x - _x.x, y - _x.y);
    }
    Point operator *(const ld _x) const
    {
        return Point(x*_x, y*_x);
    }
    Point operator /(const ld _x) const
    {
        return Point(x/_x, y/_x);
    }
};

ld dot(Point A, Point B)
{
    return A.x*B.x + A.y*B.y;
}

ld dist(Point A, Point B)
{
    return dot(B-A, B-A);
}

ld cross(Point A, Point B)
{
    return A.x*B.y - A.y*B.x;
}

//intersection point
bool doTheyIntersect(Point A, Point dA, Point B, Point dB)
{
    B = B - A;
    if(cross(dA, dB) == 0 || cross(B, dB)/cross(dA, dB) < 0)
        return 0;
    return 1;
}

Point intersect(Point A, Point dA, Point B, Point dB)
{
    B = B - A;
    return A + dA*cross(B, dB)/cross(dA, dB);
}

//collinear
const ld EPS = numeric_limits<ld>::epsilon();
bool linesParallel(Point a, Point b, Point c, Point d)
{ 
    return fabs(cross(b-a, c-d)) < EPS; 
}

bool linesCollinear(Point a, Point b, Point c, Point d)
{ 
    return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS; 
}

const int MAXN = 25005;
int N;
ld s[MAXN];
Point p[MAXN], dP[MAXN];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> p[i].x >> p[i].y >> dP[i].x >> dP[i].y >> s[i];
    bool inter = 0;
    ld ans1 = numeric_limits<ld>::infinity(), ans2 = 1;
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
        {
            dbg(i, j);
            if(doTheyIntersect(p[i], dP[i], p[j], dP[j]) && doTheyIntersect(p[j], dP[j], p[i], dP[i]))
            {
                dbg("intersect");
                ld d1 = sqrt(dist(intersect(p[i], dP[i], p[j], dP[j]), p[i]));
                ld d2 = sqrt(dist(intersect(p[i], dP[i], p[j], dP[j]), p[j]));
                if(d1 * s[j] > d2)
                {
                    if(!inter || (s[i] && d1 * ans2 < ans1 * s[i]))
                    {
                        ans1 = d1;
                        ans2 = s[i];
                    }
                }
                else
                {
                    if(!inter || (s[i] && d2 * ans2 < ans1 * s[j]))
                    {
                        ans1 = d2;
                        ans2 = s[j];
                    }
                }
                inter = 1;
            }
            else if(linesCollinear(p[i], p[i] + dP[i], p[j], p[j] + dP[j]))
            {
                dbg("collinear");
                ld t = (p[j].x - p[i].x)/dP[j].x;
                ld d = sqrt(dist(p[i], p[j]));
                if(dP[j].x == -dP[i].x)
                {
                    dbg("diff");
                    if(t < 0)
                        continue;
                    if(s[i] > s[j])
                    {
                        if(!inter || d * ans2 < ans1 * s[i])
                        {
                            ans1 = d;
                            ans2 = s[i];
                        }
                    }
                    else
                    {
                        if(!inter || d * ans2 < ans1 * s[j])
                        {
                            ans1 = d;
                            ans2 = s[j];
                        }
                    }
                }
                else
                {
                    dbg("same", d, s[i]);
                    if(t < 0 && (!inter || d * ans2 < ans1 * s[j]))
                    {
                        ans1 = d;
                        ans2 = s[j];
                    }
                    else if(!inter || d * ans2 < ans1 * s[i])
                    {
                        ans1 = d;
                        ans2 = s[i];
                    }
                }
                inter = 1;
                dbg(t);
            }
        }
    cout.setf(ios::fixed);
    cout.precision(15);
    if(!inter)
        cout << "No show :(\n";
    else
        cout << ans1/ans2 << "\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

