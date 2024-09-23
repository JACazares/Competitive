#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    while(cin >> a >> b)
        cout << abs(a - b) << "\n";
    return 0;
}