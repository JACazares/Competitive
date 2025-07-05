#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main ()
{
	int N;
	string S;
	cin >> N;
	cin >> S;
	
	ll ans = 0;
	for ( int i = N - 1; i >= 0; i-- )
	{
		ans <<= 1;
		if ( S[i] == 'B' )
			ans++;
	}
	
	cout << ans << "\n";
	return 0;
}
