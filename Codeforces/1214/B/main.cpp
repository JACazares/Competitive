#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int b, g, n;

int main ()
{
	cin >> b >> g >> n;
	n = min ( b + g - n, n );
	cout << min ( b, min ( g, n ) ) + 1 << "\n";
	return 0;
}
