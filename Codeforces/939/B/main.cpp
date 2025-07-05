#include <iostream>
using namespace std;
typedef long long int lld;

lld N, K, a, maxim, type, box;

int main ()
{
	cin >> N >> K;
	for ( int i = 0; i < K; i++ )
	{
		cin >> a;
		if ( lld(N / a) * a > maxim )
			maxim = lld( N / a) * a, type = i, box = a;
	}
	
	if ( box != 0 )
		cout << type + 1 << " " << N / box << "\n";
	else
		cout << "1 0\n";
	return 0;
}
