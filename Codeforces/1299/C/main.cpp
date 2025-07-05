#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	vi a(N);
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	deque < pll > S;
	pll t, curr;
	for ( int i = 0; i < N; i++ )
	{
		if ( !S.empty() )
			t = S.back();
		curr = {a[i], 1};
		while ( !S.empty() && t.first * (t.second + curr.second) > (t.first + curr.first) * t.second )
		{
			curr.first += t.first;
			curr.second += t.second;
			S.pop_back();
			if ( !S.empty() )
				t = S.back();
		}
		S.push_back ( curr );
	}
	cout.setf ( ios::fixed );
	cout.precision ( 10 );
	for ( auto i : S )
		for ( int j = 0; j < i.second; j++ )
			cout << (double)i.first / i.second << "\n";
	return 0;
}
