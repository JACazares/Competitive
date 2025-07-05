#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long int lld;

double K, D, T, firstAns, secondAns, thirdAns, ans;

bool solve( double x ) 
{
	if ( x <= K )
		return x >= ( T - ( firstAns * secondAns ) );
	else
		return K + ( ( x - K ) / 2 ) >= ( T - ( firstAns * secondAns ) );
}

double binSearch( double left, double right, int cnt )
{
	double mid = (left + right) / 2;
	if ( cnt == 60 )
		return mid;

	bool val = solve(mid);
	if ( val == 1 )
		return binSearch( left, mid, cnt + 1 );
	else
		return binSearch( mid, right, cnt + 1 );	
}

int main () {
	cin >> K >> D >> T;
	D = ceil(K / D) * D;

	firstAns = K + ( (D - K) / 2 );
	secondAns = floor(T / firstAns);

	thirdAns = binSearch( 0, D, 0 );

	ans = ( D * secondAns ) + thirdAns;

	cout << fixed << setprecision(9) << ans << "\n";
	return 0;
}
