#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;

int main ()
{
	cin >> T;
	string S;
	int N;
	while ( T-- )
	{
		cin >> N >> S;
		int ans = N;
		for ( int i = 0; i < N; i++ )
			if ( S[i] == '1' )
				ans = max ( ans, max ( 2*(i+1), 2*(N - i) ) );
		cout << ans << "\n";
	}
	return 0;
}
