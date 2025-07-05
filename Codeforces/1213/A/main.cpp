#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, a, ans[2];

int main ()
{
	cin >> N;
	for ( int i = 0; i < N; i++ )
		cin >> a, ans[a%2]++;
	cout << min ( ans[0], ans[1] ) << "\n";
	return 0;
}
