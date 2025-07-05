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
		int N, M;
		cin >> N >> M;
		cout << (N % M == 0 ? "YES" : "NO") << "\n";
	}
	return 0;
}
