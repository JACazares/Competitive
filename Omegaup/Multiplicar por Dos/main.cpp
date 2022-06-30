#include <bits/stdc++.h>
using namespace std;

int a, b, res;

int main()
{
    cin >> a >> b;
    res = a>b ? a/b : b/a;
    if(res%2 == 0)
        cout << "felizmil";
    else
        cout << "tristemil";
    return 0;
}
