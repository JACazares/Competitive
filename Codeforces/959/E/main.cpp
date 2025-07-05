#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lld;

lld N, ans, f[42], lastOne = -1;
string s;

string binary ( lld x ) 
{
	if ( x == 0 )
		return "";

	if ( x & 1 )
		return "1" + binary ( x / 2 );
	else
		return "0" + binary ( x / 2 );
}



int main ()
{
	cin >> N;
	s = binary ( N );

	f[0] = 0;
	for ( lld i = 1; i < 42; i++ )
	{
		if ( i > 0 )
			f[i] = 2 * f[i - 1];
		f[i] += pow ( 2, i - 1);
	}

	for ( lld i = 0; i < s.length(); i++ )
	{
		if ( s[i] == '1' )
		{
			ans += f[ i ];
			if ( lastOne != -1)
				ans += pow( 2, i );
			lastOne = i;
		}
	}

	cout << ans << "\n";

	return 0;
}
