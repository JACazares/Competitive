#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	char a, x, b;
	int in[3] = {0, 0, 0}, out[3] = {0, 0, 0};
	for ( int i = 0; i < 3; i++ )
	{
		cin >> a >> x >> b;
		if ( x == '<' )
			out[a - 'A']++, in[b - 'A']++;
		else
			in[a - 'A']++, out[b - 'A']++;
	}
	
	char A = ' ', B = ' ', C = ' ';
	for ( int i = 0; i < 3; i++ )
	{
		if ( in[i] == 0 )
			A = i + 'A';
		if ( out[i] == 0 )
			C = i + 'A';
	}
	
	if ( A == ' ' )
		cout << "Impossible\n";
	else
	{
		if ( (A == 'A' && C == 'B') || (A == 'B' && C == 'A') )
			B = 'C';
		else if ( (A == 'A' && C == 'C') || (A == 'C' && C == 'A') )
			B = 'B';
		else if ( (A == 'B' && C == 'C') || (A == 'C' && C == 'B') )
			B = 'A';
		
		cout << A << B << C << "\n";
	}
	return 0;
}
