#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 100005
using namespace std;
typedef long long int lld;

struct Query
{
	lld Start, End, idx;
};

lld N, M, K, a[MAXN], b[MAXN], bucket[1000005], block;
lld DS[MAXN], ans, answer[MAXN];
Query query[MAXN];

bool cmp( Query A, Query B )
{
	if ( A.Start / block == B.Start / block )
		return A.End < B.End;
	return A.Start / block < B.Start / block;
}

int main()
{
	cin >> N >> M >> K;
	for ( lld i = 1; i <= N; i++ )
	{
		cin >> a[i];
		b[i] = b[i - 1];
		b[i] ^= a[i];
	}
	block = ceil( sqrt(N) );

	for ( lld i = 0; i < M; i++ )
	{
		cin >> query[i].Start >> query[i].End;
		query[i].idx = i;
	}
	sort( query, query + M, cmp );

	lld leftpnt = query[0].Start, rightpnt = query[0].End;
	lld Left = 0, Right = 0;

	for ( lld i = leftpnt; i <= rightpnt; i++ )
	{
		if ( DS[b[i] ^ K] )
			ans+= DS[b[i] ^ K];
		DS[b[i]]++;
	}

	answer[query[0].idx] = ans + DS[b[leftpnt - 1] ^ K];

	for ( lld k = 1; k < M; k++ )
	{
		Left = query[k].Start;
		Right = query[k].End;

		while ( rightpnt < Right ) {
			rightpnt++;

			ans += DS[b[rightpnt] ^ K];
			DS[b[rightpnt]]++;
		}
		
		while ( rightpnt > Right ) {
			DS[b[rightpnt]]--;
			ans -= DS[b[rightpnt] ^ K];

			rightpnt--;
		}

		while ( leftpnt > Left ) {
			leftpnt--;

			ans += DS[b[leftpnt] ^ K];
			DS[b[leftpnt]]++;
		}

		while ( leftpnt < Left ) {
			DS[b[leftpnt]]--;
			ans -= DS[b[leftpnt] ^ K];

			leftpnt++;
		}

		answer[query[k].idx] = ans + DS[ b[ Left - 1 ] ^ K];
	}

	for ( lld i = 0; i < M; i++ )
		cout << answer[i] << "\n";
	return 0;
}
