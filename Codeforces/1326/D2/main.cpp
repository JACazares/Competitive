#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e6 + 5;
const ll P = 31, MOD = 1311870831664661LL;
ll pot[MAXN], suf[MAXN], pre[MAXN];
string S;

void precalc()
{
	pot[0] = 1;
	for ( int i = 1; i < S.length(); i++ )
	{
		pot[i] = (pot[i - 1] * P) % MOD;
		pot[i] %= MOD;
	}
	suf[S.length()] = 0;
	for ( int i = S.length() - 1; i >= 0; i-- )
	{
		suf[i] = (suf[i + 1] * P) % MOD + (S[i] - 'a');
		suf[i] %= MOD;
	}
	pre[0] = 0;
	for ( int i = 0; i < S.length(); i++ )
	{
		if ( i )
			pre[i] = (pre[i - 1] * P) % MOD;
		pre[i] += (S[i] - 'a');
		pre[i] %= MOD;
	}
}

ll check ( int l, int r )
{
	return ((suf[l] - (pot[r - l + 1]*suf[r + 1]) % MOD)%MOD + MOD) % MOD;
}

ll check2 ( int l, int r )
{
	if ( l == 0 )
		return pre[r];
	return ((pre[r] - (pot[r - l + 1]*pre[l - 1]) % MOD)%MOD + MOD) % MOD;
}

bool isPalin ( int l, int r )
{
	if ( check ( l, r ) == check2 ( l, r ) )
		return true;
	return false;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int T;
	cin >> T;
	while ( T-- )
	{
		cin >> S;
		precalc();
		int lpnt, rpnt;
		for ( lpnt = 0, rpnt = S.length() - 1; lpnt < rpnt; lpnt++, rpnt-- )
			if ( S[lpnt] != S[rpnt] )
				break;
		
		if ( lpnt >= rpnt )
		{
			cout << S << "\n";
			continue;
		}
		int middleL = lpnt;
		for ( int i = lpnt; i <= rpnt; i++ )
			if ( isPalin ( lpnt, i ) )
				middleL = i;
		int middleR = rpnt;
		for ( int i = rpnt; i >= lpnt; i-- )
			if ( isPalin ( i, rpnt ) )
				middleR = i;
		
		if ( middleL - lpnt > rpnt - middleR )
		{
			for ( int i = 0; i <= middleL; i++ )
				cout << S[i];
			for ( int i = rpnt + 1; i < S.length(); i++ )
				cout << S[i];
			cout << "\n";
		}
		else
		{
			for ( int i = 0; i < lpnt; i++ )
				cout << S[i];
			for ( int i = middleR; i < S.length(); i++ )
				cout << S[i];
			cout << "\n";
		}
	}
	return 0;
}
