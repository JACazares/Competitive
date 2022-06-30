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

const int MAXN = 5005;
int N, a[MAXN], pos[MAXN], DP[MAXN], pre[MAXN][MAXN];
int BIT_u[MAXN], BIT_p[MAXN];

void upd_u(int _pos)
{
	for(; _pos <= N; _pos += _pos&-_pos)
		BIT_u[_pos]++;
}

void upd_p(int _pos)
{
	for(; _pos <= N; _pos += _pos&-_pos)
		BIT_p[_pos]++;
}

int qry_u(int _pos)
{
	int res = 0;
	for(; _pos; _pos -= _pos&-_pos)
		res += BIT_u[_pos];
	return res;
}

int qry_p(int _pos)
{
	int res = 0;
	for(; _pos; _pos -= _pos&-_pos)
		res += BIT_p[_pos];
	return res;
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
			BIT_p[j] = 0;
			
		pre[i][i] = qry_u(N) - qry_u(pos[i]);
		upd_p(pos[i]);
		for(int j = i + 1; j <= N; j++)
		{
			pre[i][j] = pre[i][j - 1] + qry_p(pos[j]) + qry_u(N) - qry_u(pos[j]);
			upd_p(pos[j]);
		}
		
		upd_u(pos[i]);
	}
	
	DP[1] = 0;
	for(int l = 2; l <= N; l++)
	{
		DP[l] = (1 << 30);
		for(int j = l; j >= 1; j--)
			DP[l] = min(DP[l], pre[j][l] + DP[j - 1]);
	}
	
	cout << DP[N] << "\n";
	return 0;
}
