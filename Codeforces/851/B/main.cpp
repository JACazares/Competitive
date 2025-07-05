#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if ( (y2-y1)*(x3-x2) == (y3-y2)*(x2-x1) )
		cout << "NO\n";
	else if ( pow(x1-x2, 2) + pow(y2-y1, 2) != pow(x3-x2, 2) + pow(y3-y2, 2) )
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}
