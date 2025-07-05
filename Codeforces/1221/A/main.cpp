#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	int Q;
	cin >> Q;
	while ( Q-- )
	{
		int N;
		cin >> N;
		
		int k;
		map < int, int > f;
		for ( int i = 1; i <= (1 << 29); i *= 2 )
			f[i] = 0;
		
		int a;
		for ( int i = 0; i < N; i++ )
		{
			cin >> a;
			f[a]++;

			k = a;
			while ( k < 2048 && f[k] == 2 )
				f[k] = 0, f[2 * k]++, k *= 2;
		}
		
		cout << (f[2048] ? "YES" : "NO") << "\n";
	}
	
	return 0;
}
