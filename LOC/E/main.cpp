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

const int MAXN = 1005;
int N, a[MAXN], DP[MAXN], nxt[MAXN];

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	
	for(int i = N; i >= 1; i--)
	{
		nxt[i] = N + 1;
		DP[i] = 1;
		for(int j = i + 1; j <= N; j++)
		{
			if(DP[j] + 1 > DP[i] && a[j] > a[i])
			{
				DP[i] = DP[j] + 1;
				nxt[i] = j;
			}
		}
		if(DP[i] >= DP[0])
		{
			DP[0] = DP[i];
			nxt[0] = i;
		}
	}
	
	int curr = nxt[0];
	cout << DP[curr] << "\n";
	while(curr != N + 1)
	{
		cout << curr << " ";
		curr = nxt[curr];
	}
	cout << "\n";
	return 0;
}
