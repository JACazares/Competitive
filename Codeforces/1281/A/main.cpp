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
	int T;
	cin >> T;
	while ( T-- )
	{
		string S;
		cin >> S;
		int N = S.length();
		string ans = "";
		if ( N >= 2 && S[N - 1] == 'o' && S[N - 2] == 'p' )
			ans = "FILIPINO";
		else if ( N >= 4 && S[N - 1] == 'u' && S[N - 2] == 's' && S[N - 3] == 'e' && S[N - 4] == 'd' )
			ans = "JAPANESE";
		else if ( N >= 4 && S[N - 1] == 'u' && S[N - 2] == 's' && S[N - 3] == 'a' && S[N - 4] == 'm' )
			ans = "JAPANESE";
		else
			ans = "KOREAN";
		cout << ans << "\n";
	}
	return 0;
}
