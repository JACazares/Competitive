#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
        optimizar_io

        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            cout << b << "\n";
            a -= b;
            cout << a/2;
        } else
        {
            cout << a << "\n";
            b -= a;
            cout << b/2;
        }

        return 0;
}
