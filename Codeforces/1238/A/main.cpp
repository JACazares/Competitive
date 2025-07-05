#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll T, x, y;

int main ()
{
	cin >> T;
	while ( T-- )
	{
		cin >> x >> y;
		if ( x - y == 1 )
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
