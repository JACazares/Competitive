#include <iostream>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main ()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = (a+b+c)*(a+b+c) - a*a - c*c - e*e;
    cout << ans << "\n";
	return 0;
}
