#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 55;
int N, M, K;
ll a[MAXN], b[MAXN];

void solve()
{
	ll suma = 0;
	
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
		suma += a[i];
	}
		
	ll mina = a[0], maxa = a[0];
	for(int i = 0; i < N; i++)
	{
		mina = min(mina, a[i]);
		maxa = max(maxa, a[i]);
	}
	
	for(int i = 0; i < M; i++)
		cin >> b[i];
	
	ll minb = b[0], maxb = b[0];
	for(int i = 0; i < M; i++)
	{
		minb = min(minb, b[i]);
		maxb = max(maxb, b[i]);
	}
	
	if(K%2 == 0)
	{
		if(mina >= maxb)
			cout << suma - maxa + minb << "\n";
		else
			cout << suma << "\n";
	}
	else
		cout << max(suma, suma - mina + maxb) << "\n";
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
