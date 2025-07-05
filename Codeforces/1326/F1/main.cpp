#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 15;
int N;
string adj[MAXN];
map<string, ll> MP;

void solve ( int mask, int last, string ans )
{
	if ( mask == (1 << N) - 1 )
	{
		MP[ans]++;
		return;
	}
	for ( int i = 1; i <= N; i++ )
		if ( !(mask & (1 << (i - 1))) )
			solve ( mask | (1 << (i - 1)), i, ans + adj[last][i - 1] );
}

void print ( int n, string s )
{
	if ( n == N - 1 )
	{
		cout << MP[s] << " ";
		return;
	}
	print ( n + 1, s + "0" );
	print ( n + 1, s + "1" );
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( int i = 1; i <= N; i++ )
		cin >> adj[i];
	for ( int i = 1; i <= N; i++ )
		solve ( (1 << (i - 1)), i, "" );
	print(0, "");
	cout << "\n";
	return 0;
}
