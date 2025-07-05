#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
double a, b, c, d, k;

int main ()
{
	cin >> T;
	while ( T-- )
	{
		cin >> a >> b >> c >> d >> k;
		k -= ceil ( a / c ) + ceil ( b / d );
		
		cout.setf ( ios::fixed );
		cout.precision ( 0 );
		if ( k >= 0 )
			cout << ceil ( a / c ) << " " << ceil ( b / d ) << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
