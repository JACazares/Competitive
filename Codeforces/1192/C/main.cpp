#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAXL = 63;
const ll MOD = 998244353;
 
int N, aux, words[15][MAXL][MAXL], ans, maxim, pre[MAXL][MAXL][MAXL][15];
string S;
map < string, int > MP;
 
int convert ( char c )
{
	if ( 'a' <= c && c <= 'p' )
		return c - 'a';
	if ( 'A' <= c && c <= 'P' )
		return c - 'A' + 16;
	if ( 'q' <= c && c <= 'z' )
		return c - 'q' + 32;
	if ( 'Q' <= c && c <= 'Z' )
		return c - 'Q' + 42;
	if ( '0' <= c && c <= '9' )
		return c - '0' + 52;
	return 62;
}
 
int solve ( int l1, int l2, int l3, int s )
{
	ll ret = 0;
	for ( int i = 0; i < maxim; i++ )
	{
		ret += (words[s][l1][i]*words[s][l2][i]%MOD)*words[s][l3][i]%MOD;
		ret %= MOD;
	}
	return ret;
}
 
int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
 
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		cin >> S;
		if ( MP[S] )
			continue;
		MP[S] = 1;
		aux = S.length();
		words[aux][convert(S[0])][convert(S[aux-1])]++;
		reverse(S.begin(), S.end());
		if ( MP[S] )
			continue;
		MP[S] = 1;
		words[aux][convert(S[0])][convert(S[aux-1])]++;
		maxim = max ( maxim, max ( convert(S[0]), convert(S[aux-1]) ) );
	}
	maxim++;
 
	for ( int a1 = 0; a1 < maxim; a1++ )
		for ( int a2 = 0; a2 < maxim; a2++ )
			for ( int a3 = 0; a3 < maxim; a3++ )
				for ( int i = 3; i <= 10; i++ )
					pre[a1][a2][a3][i] = solve ( a1, a2, a3, i );
 
	ll A, B, C, D;
	for ( int a1 = 0; a1 < maxim; a1++ )
	for ( int a2 = 0; a2 < maxim; a2++ )
	for ( int a3 = 0; a3 < maxim; a3++ )
	for ( int a4 = 0; a4 < maxim; a4++ )
		for ( int i = 3; i <= 10; i++ )
		{
			A = pre[a1][a2][a3][i];
			B = pre[a2][a3][a4][i];
			C = pre[a1][a2][a4][i];
			D = pre[a1][a3][a4][i];
 
			ans += ((A*B%MOD)*C%MOD)*D%MOD;
			ans %= MOD;
		}
 
	cout << ans << "\n";
	return 0;
}
