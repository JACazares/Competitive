    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <math.h>
    #define sz(x) x.size()
    #define all(x) x.begin(), x.end()

    using namespace std;
    using ll = long long;

    template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
    template <class T>
    struct Point
    {
        typedef Point P;
        T x, y;
        explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

        bool operator < (P p) const { return tie(x,y) < tie(p.x, p.y); }
        bool operator ==(P p) const { return tie(x, y) == tie(p.x, p.y); }
        P operator+ (P p) const { return P(x+p.x, y+p.y);}
        P operator- (P p) const { return P(x-p.x, y-p.y);}
        T dot(P p) const { return x*p.x + y*p.y; }
        T cross(P p) const { return x*p.y - y*p.x; }
        T cross(P a, P b) const { return (a-*this).cross(b-*this); }
        T dist2() const { return x*x + y*y; }
        double dist() const { return sqrt((double)dist2()); }
    };

    typedef Point<double> P;
    vector<P> convexHull(vector<P> pts)
    {
        if(sz(pts) <= 1)
            return pts;

        sort(all(pts));

        vector<P> h(sz(pts) + 1);
        int s = 0, t = 0;
        for(int it = 2; it--; s = --t, reverse(all(pts)))
        {
            for(P p : pts)
            {
                while(t >= s + 2 && h[t - 2].cross(h[t-1], p) <= 0) t--;
                h[t++] = p;
            }
        }
        return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
    }
    vector<P > a,b;

    int n;
    bool check(double ang){
        vector<P> a1;
        P sm (0,0), smb(0,0);
        for(auto A: a){
            P v1;
            v1.x =A.x * cos(ang) - A.y * sin(ang);
            v1.y= A.x * sin(ang) + A.y * cos(ang);
            a1.push_back(v1);
            sm = sm + v1 ;
        }
        for(auto B : b)
            smb = smb+ B;
        sm.x /= n;
        sm.y /= n;
        smb.x /= n;
        smb.y /= n;
        for(int i =0 ; i < n; i++)
            a1[i] = a1[i] + smb - sm;
        sort(a1.begin(), a1.end());
        sort(b.begin(),b.end());
        for(int i = 0; i < n; i++){
            if(a1[i] != b[i]) return 0;
        }
        return 1;
    
    }
    int main()
    {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].x >> a[i].y;

        }
        for(int i = 0; i < n; i++){
            cin >> b[i].x>> b[i].y;
        }
        vector<P > ch1 = convexHull(a), ch2 = convexHull(b);
        P v1 = ch1[1] - ch1[0];
        double ans =  acos(-1);
        for(int i = 0; i < n; i++){
            P v2 = ch2[(i+1)%n] - ch2[i];

            double ang = acos(v1.dot(v2) / v1.dist() / v2.dist());
            if(ang < 0) ang += acos(-1);
            if(check(ang)) ans = min(ans, ang);
        }
        printf("%.7f\n", ans);
        return 0;
    }