#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200005;

int N, K, x, cnt;
priority_queue < int > ans[MAXN];

int main ()
{
	cin >> N >> K;
	for ( int i = 0; i < N; i++ )
	{
		cin >> x;
		
		cnt = 0;
		while ( x )
		{
			if ( ans[x].size() < K )
				ans[x].push ( cnt );
			else if ( ans[x].top() > cnt )
				ans[x].pop(), ans[x].push ( cnt );
			cnt++;
			x /= 2;
		}
		if ( ans[x].size() < K )
			ans[x].push ( cnt );
		else if ( ans[x].top() > cnt )
			ans[x].pop(), ans[x].push ( cnt );
		cnt++;
	}
	
	int res = (1 << 30), aux;
	for ( int i = 0; i < MAXN; i++ )
	{
		if ( ans[i].size() == K )
		{
			aux = 0;
			while ( !ans[i].empty() )
				aux += ans[i].top(), ans[i].pop();
			res = min ( res, aux );
		}
	}
	
	cout << res << "\n";
	return 0;
}
