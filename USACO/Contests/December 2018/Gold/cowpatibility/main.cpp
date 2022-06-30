/*
ID: coa21
PROG: cowpatibility
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#define vi vector < int >
#define pii pair < int, int >

#define UPLOAD 1
#if UPLOAD
#define cin ccin
#define cout ccout
#endif

using namespace std;
typedef long long ll;
ifstream ccin("cowpatibility.in");
ofstream ccout("cowpatibility.out");

int a[5], k, ret, e;
ll N, total, ans;
vi aux, arr;
unordered_map < int, int > MP1;
map < pii, int > MP2;
map < pair < int, pii >, int > MP3;
map < pair < pii, pii >, int > MP4;
map < vi, int > MP;

int qry ( )
{
	ret = 0;
	for ( int i = 1; i < (1 << 5); ++i )
	{
		e = 0;
		arr.clear();
		for ( int j = 0; j < 5; ++j )
			if ( i & (1 << j) )
				arr.push_back ( a[j] );

		e = arr.size();
		if ( e == 1 )
			k = MP1[arr[0]];
		else if ( e == 2 )
			k = MP2[{arr[0], arr[1]}];
		else if ( e == 3 )
			k = MP3[{arr[0], {arr[1], arr[2]}}];
		else if ( e == 4 )
			k = MP4[{{arr[0], arr[1]}, {arr[2], arr[3]}}];
		else
			k = MP[arr];
		
		if ( e & 1 )
			ret = ret + k;
		else
			ret = ret - k;
	}
	return ret;
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for ( int t = 0; t < N; ++t )
	{
		for ( int i = 0; i < 5; ++i )
			cin >> a[i];

		stable_sort ( a, a + 5 );

		if ( t > 0 )
			ans = ans + qry ( );

		if ( t < N - 1 )
		{
			for ( int i = 1; i < (1 << 5); ++i )
			{
				aux.clear();
				for ( int j = 0; j < 5; ++j )
					if ( i & (1 << j) )
						aux.push_back ( a[j] );

				e = aux.size();
				if ( e == 1 )
					++MP1[aux[0]];
				else if ( e == 2 )
					++MP2[{aux[0], aux[1]}];
				else if ( e == 3 )
					++MP3[{aux[0], {aux[1], aux[2]}}];
				else if ( e == 4 )
					++MP4[{{aux[0], aux[1]}, {aux[2], aux[3]}}];
				else
					++MP[aux];
			}
		}
	}

	total = (N * (N - 1)) / 2;
	cout << total - ans << "\n";
	return 0;
}
