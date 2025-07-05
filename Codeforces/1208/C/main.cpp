#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1005;

int N, a[MAXN][MAXN], cnt;

int main ()
{
	cin >> N;
	for ( int i = 0; i < N; i += 2 )
	{
		for ( int j = 0; j < N; j += 2 )
		{
			a[i][j] = cnt;
			a[i][j + 1] = cnt + 1;
			a[i + 1][j] = cnt + 2;
			a[i + 1][j + 1] = cnt + 3;
			cnt += 4;
		}
	}

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
