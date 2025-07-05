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
	string S;
	cin >> N;
	cin >> S;
	for ( char c = 'z'; c >= 'b'; c-- )
	{
		int first = 0;
		string V = "";
		for ( int i = 0; i < S.length(); i++ )
		{
			if ( S[i] == c )
				continue;
			if ( !((first && (S[first - 1] == (char)(c - 1))) || (S[i] == (char)(c - 1))) )
				for ( int j = first; j < i; j++ )
					V += S[j];
			V += S[i];
			first = i + 1;
		}
		if ( S[S.length() - 1] == c )
			if ( !((first && (S[first - 1] == (char)(c - 1)))) )
				for ( int j = first; j < S.length(); j++ )
					V += S[j];
		swap ( V, S );
	}
	cout << N - S.length() << "\n";
	return 0;
}
