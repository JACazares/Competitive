#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int gcd ( int a, int b )
{
	if ( b == 0 )
		return a;
	return gcd ( b, a % b );
}

int main ()
{
	int N;
	cin >> N;
	vector < int > ans;
	int x, g, G = 0;
	for ( int i = 0; i < N; i++ )
	{
		g = 0;
		for ( int j = 0; j < N; j++ )
			cin >> x, g = gcd ( g, x );
		ans.push_back ( g );
		G = gcd ( G, g );
	}
	ans[0] /= G;
	for ( auto i : ans )
		cout << i << " ";
	cout << "\n";
	return 0;
}
