#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MAXN 100005
#define pii pair < lld, lld > 
#define mp make_pair

using namespace std;
typedef long long lld;

lld N, K, L, R, a[MAXN], b[MAXN], c[MAXN], prefix[MAXN], maxim, minim;
lld s, e, mid, aux, cnt = 1, BIT[2 * MAXN], BIT2[2 * MAXN];
pii ans, val;
unordered_map < lld, lld > MP;

lld lookfor ( lld x )
{
	lld auxpos = lower_bound ( c + 1, c + cnt, x ) - c;

	if ( c[auxpos] == x )
		return auxpos;
	return auxpos - 1;
}

void update ( lld pos, lld _val )
{
	while ( pos <= cnt )
	{
		BIT[pos] += _val;
		pos += (pos & -pos);
	}
}

lld query ( lld pos )
{
	lld ret = 0;
	while ( pos > 0 )
	{
		ret += BIT[pos];
		pos -= (pos & -pos);
	}

	return ret;
}

void update2 ( lld pos, lld _val )
{
	while ( pos < cnt )
	{
		BIT2[pos] += _val;
		pos += (pos & -pos);
	}
}

lld query2 ( lld pos )
{
	lld ret = 0;
	while ( pos > 0 )
	{
		ret += BIT2[pos];
		pos -= (pos & -pos);
	}

	return ret;
}


pii solve ( lld sum )
{
	lld cntL = 0;
	lld ret = 0, ret2 = 0, q1 = 0;

	for ( lld i = 0; i <= N; i++ )
		BIT[i] = 0, BIT2[i] = 0;

	for ( lld i = 0; i <= N - L; i++ )
	{
		update ( MP[prefix[i]], 1 );
		update2( MP[prefix[i]], prefix[i] );

		if ( (i + L) - cntL > R )
		{
			update ( MP[prefix[cntL]], -1 );
			update2( MP[prefix[cntL]], -prefix[cntL] );
			cntL++;
		}

		q1 = query ( lookfor(prefix[i + L] - sum) );

		ret += q1;
		//cout << (q1 * prefix[i + L]) << ", " << query2(lookfor(prefix[i + L] - sum)) << "\n";
		ret2+= (q1 * prefix[i + L]) - query2(lookfor(prefix[i + L] - sum));
	}

	return mp ( ret, ret2 );
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> L >> R;
	for ( lld i = 1; i <= N; i++ )
	{
		cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
		b[i] = prefix[i];
		maxim += (a[i] >= 0 ? a[i] : 0 );
		minim += (a[i] <= 0 ? a[i] : 0 ); 
	}

	sort ( b, b + N + 1 );

	for ( lld i = 0; i <= N; i++ )
		if ( i == 0 or b[i] != b[i - 1] )
			c[cnt++] = b[i];
	
	for ( lld i = 1; i < cnt; i++ )
		MP[c[i]] = i;

	s = minim, e = maxim;


	while ( s <= e )
	{
		mid = (s + e) / 2;
		val = solve ( mid );

		if ( val.first < K )
			e = mid - 1;
		else
		{
			ans = val;
			aux = mid;
			s = mid + 1;
		}
	}

	ans.second -= ( (ans.first - K) * aux );
	cout << ans.second << "\n";
	return 0;
}
