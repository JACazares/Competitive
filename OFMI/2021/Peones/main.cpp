#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 105;
int N, M, a[MAXN][MAXN], col[MAXN], cnt[MAXN], tot = 0;

int main()
{
	cin >> N >> M;
	for(int i = N; i >= 1; i--)
		for(int j = 1; j <= M; j++)
		{
			cin >> a[i][j];
			if(a[i][j] && i >= j)
			{
				cnt[j] = i - j;
				col[j] = 1;
			}
		}

	int X, Y;
	cin >> X >> Y;
	
	bool ans = 1;
	for(int i = 2; i <= Y; i++)
	{
		if(!col[i])
			ans = 0;
		tot += cnt[i];
	}
	if(X < Y)
		ans = 0;
	cout << (ans ? X + Y - 2 + tot : -1) << "\n";
	return 0;
}
