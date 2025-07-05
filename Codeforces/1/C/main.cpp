#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double pi = 4 * atan(1.0);

class Point
{
public:
    double x, y;

    Point() : x(0), y(0) {};
    Point(double x_, double y_) : x(x_), y(y_) {};

    Point operator*(const double a) { return Point(x*a, y*a); }
    Point operator/(const double a) { return Point(x/a, y/a); }

    Point operator+(const Point& a) { return Point(x + a.x, y + a.y); }
    Point operator-(const Point& a) { return Point(x - a.x, y - a.y); }
    
    double norm2() { return x*x + y*y; }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << " " << p.y << ")";
        return os;
    }
};

Point circumcenter(Point a, Point b, Point c)
{
    Point b_ = b - a;
    Point c_ = c - a;
    
    double d_ = 2*(b_.x*c_.y - b_.y*c_.x);

    Point u_ = Point(c_.y * b_.norm2() - b_.y * c_.norm2(), b_.x*c_.norm2() - c_.x*b_.norm2()) / d_;

    return u_ + a;
}

bool close(double a, double b, double eps = 1e-3)
{
    return abs(a-b) < eps;
}

double get_angle(Point a, Point b)
{
    // cout << a << " " << b << "\n";
    // cout << (a.x*b.x) << "\n";
    // cout << (a.y*b.y) << "\n";
    // cout << (a.x*b.x + a.y*b.y) << "\n";
    // cout << sqrt(a.norm2() * b.norm2()) << "\n";
    // cout << "\n";
    if(close(a.x*b.x + a.y+b.y, 0))
        return pi/2;
    
    if(close((a.x*b.x + a.y*b.y), sqrt(a.norm2() * b.norm2())))
        return pi;

    if(close((a.x*b.x + a.y*b.y), -sqrt(a.norm2() * b.norm2())))
        return pi;

    return acos((a.x*b.x + a.y*b.y) / sqrt(a.norm2() * b.norm2()));
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(8);

    vector<Point> p(3);
    for(int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;
    
    Point center = circumcenter(p[0], p[1], p[2]);
    double radius2 = (p[0] - center).norm2();

    double area = 0;
    for(int n = 3; n <= 100; n++)
    {
        double angle = (2*pi)/n;

        double angle1 = get_angle(p[0]-center, p[1]-center);
        double angle2 = get_angle(p[1]-center, p[2]-center);
        double angle3 = get_angle(p[2]-center, p[0]-center);

        // cout << angle1/(2*pi) << "\n";
        // cout << angle2/(2*pi) << "\n";
        // cout << angle3/(2*pi) << "\n";
        
        double one = false, two = false, three = false;
        for(int i = 1; i < n; i++)
        {
            if(close(angle1, angle*i))
                one = true;
            if(close(angle2, angle*i))
                two = true;
            if(close(angle3, angle*i))
                three = true;
        }

        if(one && two && three)
        {
            area = n * radius2 * sin(angle) / 2.0;
            break;
        }
    }

    cout << area << "\n";
}