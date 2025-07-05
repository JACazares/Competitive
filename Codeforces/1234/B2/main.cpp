#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K, a;
unordered_map < int, int > used;
deque < int > DQ;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> K;
	for ( int i = 0; i < N; i++ )
	{
		cin >> a;
		if ( used[a] )
			continue;
		
		if ( DQ.size() == K )
		{
			used[DQ.back()] = 0;
			DQ.pop_back();
		}
		
		used[a] = 1;
		DQ.push_front ( a );
	}
	
	cout << DQ.size() << "\n";
	while ( !DQ.empty() )
		cout << DQ.front() << " ", DQ.pop_front();
	cout << "\n";
	return 0;
}
