#include <iostream>

using namespace std;

int main()
{
    int x, n, c=0, m;
    cin >> x;
    n = x;
    while (n > 2){
        m = n%2;
        if(m == 1)
            c++;
        n -= m;
        n /= 2;
    }
    cout << c+1;
    return 0;
}
