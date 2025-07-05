#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	if ( N <= 2 )
		cout << "-1\n";
	else
	{
		cout << "210";
		for ( int i = 3; i < N; i++ )
			cout << "0";
		cout << "\n";
	}
	return 0;
}
