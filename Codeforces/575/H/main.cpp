#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0, c = 0;
    cin >> n;
    for(int i = n*2; i > 1; i--)
    {
        c += i * 2;
    }
    cout << c+1;
    return 0;
}
