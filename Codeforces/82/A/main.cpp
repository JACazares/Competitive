#include <iostream>
#include <map>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int a, i = 5;

int main()
{
    map<int,string> s;
    s[0] = "Sheldon";
    s[1] = "Leonard";
    s[2] = "Penny";
    s[3] = "Rajesh";
    s[4] = "Howard";
    cin >> a;
    while(a > i)
    {
        a -= i;
        i *= 2;
    }
    i /= 5;
    a--;
    a /= i;
    cout << s[a];
    return 0;
}
