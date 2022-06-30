#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 105;
int N, M, bold[MAXN][MAXN];

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			if(c == '#')
				for(int x = 0; x < 2; x++)
					for(int y = 0; y < 2; y++)
						bold[i + x][j + y] = 1;
		}
	
	for(int i = 0; i < N; i++) 
	{
		for(int j = 0; j < M; j++)
			cout << (bold[i][j] ? '#' : '.');
		cout << "\n";
	}
	return 0;
}
