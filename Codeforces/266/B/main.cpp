#include <iostream>
using namespace std;

int N, T;
string S;

int main ()
{
	cin >> N >> T;
	cin >> S;
	for ( int t = 0; t < T; t++ )
		for ( int i = 1; i < S.length(); i++ )
			if ( S[i - 1] == 'B' && S[i] == 'G' )
				S[i] = 'B', S[i - 1] = 'G', i++;
	cout << S << "\n";
	return 0;
}
