#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main ()
{
	int N, K;
	cin >> N >> K;
	ll maxim = 0, pos, x;
	map < int, int > freq, vis;
	for ( int gap = 1; gap <= K + 1; gap++ )
	{
		cout << "? ";
		for ( int i = 1; i <= K + 1; i++ )
			if ( i != gap )
				cout << i << " ";
		cout << "\n", fflush ( stdout );
		cin >> pos;
		if ( pos == -1 )
			return 0;
		cin >> x;
		freq[x]++;
		maxim = max ( maxim, x );
	}
	cout << "! " << freq[maxim];
	cout << "\n", fflush ( stdout );
	return 0;
}
