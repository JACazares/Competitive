#include <iostream>
#include <iomanip>

using namespace std;

long long int x, y, j, a;

int main()
{
    cin >> x >> y;
    j = 1;
    if(x == 0)
    {
        cout << y*3;
        return 0;
    }
    else if(y == 0)
    {
        cout << x*2;
        return 0;
    }
    else if(y >= x)
    {
        cout << y*3;
        return 0;
    }
    else if(y == 1)
    {
        cout << x*2;
        return 0;
    }
    else if(x > y)
    {
        for(int i = 0; i < x; i++)
        {
            a+=2;
            if(a/(j*3) == 1 && a%(j*3) == 0)
            {
                a+=2;
                if(j <= y)
                    j++;
            }
            if(a > j*3 && j <= y)
                j++;
        }
    }
    if(a > (y+1)*3 && x-2 == y)
        cout << (y+1)*3;
    else 
        cout << setprecision(0) << a;
    return 0;
}
