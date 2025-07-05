#include <iostream>
using namespace std;
typedef long long int lld;

int n;

void incorrect ( int N )
{
	if ( N == 1 or N == 2 or N == 3 or N == 4 or N == 5)
	{
		cout << "-1\n";
		return;
	}

	N--;
	for ( int i = 0; i < N - 2; i++ )
		cout << "1 " << i + 2 << "\n";
	cout << "2 " << N << "\n";
	cout << "2 " << N + 1 << "\n";
}

void correct ( int node )
{
	if ( node == n )
		return;
	cout << node << " " << node + 1 << "\n";
	correct ( node + 1 );
}

int main ()
{
	cin >> n;
	incorrect ( n );
	correct ( 1 );
	return 0;
}
