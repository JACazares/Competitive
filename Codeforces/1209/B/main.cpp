#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 105;

int N, a[MAXN], b[MAXN], f, light[MAXN][505], aux, ans;
string S;

int main ()
{
	cin >> N;
	cin >> S;
	for ( int i = 0; i < N; i++ )
	{
		cin >> a[i] >> b[i];
		light[i][0] = S[i] - '0';
		for ( int j = b[i]; j <= 500; j += a[i] )
			light[i][j] = 1;
		
		for ( int j = 1; j <= 500; j++ )
			light[i][j] ^= light[i][j - 1];
	}
	
	for ( int j = 0; j <= 500; j++ )
	{
		aux = 0;
		for ( int i = 0; i < N; i++ )
			aux += light[i][j];
		ans = max ( ans, aux );
	}
	cout << ans << "\n";
	return 0;
}
