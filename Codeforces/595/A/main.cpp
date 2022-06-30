#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int i = 0, j = 0, a[110][250], b = 0;

int main()
{
    optimizar_io
    cin >> i >> j;
    for(int x = 0; x < i; x++)
    {
        for(int y = 0; y < j*2; y++)
        {
            cin >> a[x][y];
        }
    }
    for(int x = 0; x < i; x++)
    {
        for(int y = 0; y < j*2; y+=2)
        {
            if(a[x][y] == 1)
            {
                b++;
            }
            else if(a[x][y+1] == 1)
            {
                b++;
            }
        }
    }
    cout << b;
    return 0;
}
