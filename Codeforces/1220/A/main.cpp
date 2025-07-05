#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main ()
{
	int N;
	cin >> N;
	
	int one=0, zero=0;
	char c;
	while ( N-- )
	{
		cin >> c;
		if ( c == 'n' )
			one++;
		if ( c == 'z' )
			zero++;
	}
	
	while ( one-- )
		cout << "1 ";
	while ( zero-- )
		cout << "0 ";
	return 0;
}
