#include <iostream>
using namespace std;
typedef long long int lld;

int N, a[5010];

int main ()
{
	cin >> N;
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	for ( int i = 0; i < N; i++ )
		if ( a[a[a[i] - 1] - 1] - 1 == i )
		{
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
	return 0;
}
