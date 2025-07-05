#include <iostream>

using namespace std;
typedef long long int lld;

int N, M, a, bucket[1005], points = 1;

int main ()
{
	cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		cin >> a;
		bucket[a]++;
		int aux = 0;
		for ( int k = 1; k <= N; k++ )
			if ( bucket[k] >= points )
				aux++;
		if ( aux == N )
			points++;
	}
	cout << points - 1 << "\n";
	return 0;
}
