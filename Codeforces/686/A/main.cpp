#include <bits/stdc++.h>
using namespace std;
long long int n, x, d, Stress;
char c;

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        cin >> d;
        if(c == '+')
        {
            x+= d;
        }
        else if (c == '-')
        {
            if(x >= d)
                x-= d;
            else
                Stress++;
        }
    }
    cout << x << " " << Stress;
    return 0;
}
