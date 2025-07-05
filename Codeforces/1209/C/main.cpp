#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200005;

int T, N, cnt[15], low, color[MAXN], ans;
string S;

int main ()
{
	cin >> T;
	while ( T-- )
	{
		cin >> N;
		cin >> S;
		for ( int i = 0; i < 10; i++ )
			cnt[i] = 0;
		for ( int i = 0; i < N; i++ )
			color[i] = 0;
		for ( auto i : S )
			cnt[i - '0']++;
		
		low = 0;
		for ( int i = 0; i < N; i++ )
		{
			while ( !cnt[low] ) low++;
			if ( (S[i] - '0') == low )
				color[i] = 1, cnt[low]--;
			while ( !cnt[low] ) low++;
		}
		for ( int i = 0; i < N; i++ )
		{
			while ( !cnt[low] ) low++;
			if ( (S[i] - '0') == low && !color[i] )
				color[i] = 2, cnt[low]--;
			while ( !cnt[low] ) low++;
		}
		
		ans = 1;
		for ( int i = 0; i < N; i++ )
			if ( !color[i] )
				ans = 0;
			
		if ( ans )
		{
			for ( int i = 0; i < N; i++ )
				cout << color[i];
			cout << "\n";
		}
		else
			cout << "-\n";
	}
	return 0;
}
