#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int Q, N, x, sum;

int main ()
{
	cin >> Q;
	while ( Q-- )
	{
		sum = 0;
		cin >> N;
		for ( int i = 0; i < N; i++ )
			cin >> x, sum += x;
			
		cout.setf ( ios::fixed );
		cout.precision ( 0 );
		cout << ceil ( (double)sum / N ) << "\n";
	}
	return 0;
}
