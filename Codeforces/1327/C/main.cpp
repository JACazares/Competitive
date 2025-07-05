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
	int N, M, K;
	cin >> N >> M >> K;
	int x[K], y[K];
	for ( int i = 0; i < K; i++ )
		cin >> x[i] >> y[i];
	int fx[K], fy[K];
	for ( int i = 0; i < K; i++ )
		cin >> fx[i] >> fy[i];
	string ans = "";
	for ( int i = 0; i < N - 1; i++ )
		ans += "D";
	for ( int i = 0; i < M - 1; i++ )
		ans += "R";

	for ( int i = 0; i < M - 1; i++ )
	{
		for ( int j = 0; j < N - 1; j++ )
			ans += (i & 1 ? "D" : "U");
		ans += "L";
	}
	for ( int i = 0; i < N - 1; i++ )
		ans += ((M - 1) & 1 ? "D" : "U");
	cout << ans.size() << "\n";
	cout << ans << "\n";
	return 0;
}
