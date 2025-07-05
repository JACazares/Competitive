#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 ); cout.tie ( 0 );
	string S;
	cin >> S;
	
	char minim = 'z';
	for ( auto i : S )
	{
		minim = min ( minim, i );
		if ( i > minim )
			cout << "Ann\n";
		else
			cout << "Mike\n";
	}
	return 0;
}
