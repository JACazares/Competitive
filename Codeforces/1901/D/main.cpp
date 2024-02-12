#include <iostream>

using namespace std;
using ll = long long;

const int MAXN = (int)3e5 + 5;
int N;
ll a[MAXN], eff_izquierda[MAXN], eff_derecha[MAXN];
ll max_izquierda[MAXN], max_derecha[MAXN];

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		eff_izquierda[i] = a[i] + (i - 1);
		eff_derecha[i] = a[i] + (N - i);
	}
	
	if(N == 1)
	{
		cout << a[1] << "\n";
		return 0;
	}
	
	max_derecha[1] = eff_derecha[1];
	for(int i = 2; i <= N; i++)
		max_derecha[i] = max(max_derecha[i - 1], eff_derecha[i]);
	
	max_izquierda[N] = eff_izquierda[N];
	for(int i = N - 1; i >= 1; i--)
		max_izquierda[i] = max(max_izquierda[i + 1], eff_izquierda[i]);
	
	cout << "           --- target ---\n";
	for(int i = 1; i <= N; i++)
	{
		cout << "inicial " << i << ": ";
		for(int j = 1; j < i; j++)
		{
			cout.width(2);
			cout << eff_derecha[j] << " ";
		}
		cout.width(2);
		cout << a[i] << " ";
		for(int j = i + 1; j <= N; j++)
		{
			cout.width(2);
			cout << eff_izquierda[j] << " ";
		}
		cout << "\n";
	}
	
	ll ans = max(max_izquierda[2], a[1]);
	ans = min(ans, max(max_derecha[N - 1], a[N]));
	for(int i = 2; i <= N - 1; i++)
	{
		ll aux = max(max(max_izquierda[i + 1], max_derecha[i - 1]), a[i]);
		ans = min(ans, aux);
	}
	cout << ans << "\n";
	return 0;
}
