#include <iostream>
using namespace std;

string S;
int bucket[30], impares;

int main ()
{
	cin >> S;
	for ( int i = 0; i < S.length(); i++ )
		bucket[ S[i] - 'a' ]++;
	
	for ( int i = 0; i < 26; i++ )
		if ( bucket[i] & 1 )
			impares++;
	
	if ( impares & 1 || !impares )
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}
