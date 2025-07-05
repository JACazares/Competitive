#include <iostream>
#include <cstdlib>

#define optimizar_io ios_base::sync_with_stdio();cin.tie(0);

using namespace std;

int n, a, b;

int main()
{
    optimizar_io
    cin >> n >> a >> b;
    a--;
    if(a >= 0 && b >= 0)
        cout << abs(b/n - a/n);
    if(a < 0 && b >= 0)
        cout << abs(abs(b/n) + abs(a/n)) + 1;
    if(a < 0 && b < 0)
        cout << abs(b/n - a/n);
    return 0;
}

