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
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second

const int MAXN = 805;
int N, a[MAXN][MAXN];

int main()
{
	// input
	cin >> N;
	for(int i = 0; i < N; i++) // filas
		for(int j = 0; j < N; j++) // columnas
			cin >> a[i][j];
	
	// a[fila][columna]
	for(int r = -N/2; r <= N/2; r++)
		for(int c = -N/2; c <= N/2; c++)
		{
			int val = max(abs(r), abs(c));
			afuera[r+N/2][c+N/2] = val + 1;
		}

	for(int r = -N/2; r <= N/2; r++)
		for(int c = -N/2; c <= N/2; c++)
		{
			int val = max(abs(r), abs(c));
			adentro[r+N/2][c+N/2] = (N+1)/2 - val;
		}
	
	cout << "\n";
	int aux_afuera = 1, aux_adentro = 1;
	for(int r = -N/2; r <= N/2; r++)
	{
		for(int c = -N/2; c <= N/2; c++)
		{
			int val = max(abs(r), abs(c));
			cout << val << " ";

			if(a[r+N/2][c+N/2] != val + 1)
			 	aux_afuera = 0;

			if(a[r+N/2][c+N/2] != (N+1)/2 - val)
			 	aux_adentro = 0;
		}
		cout << "\n";
	}

	if(aux_afuera == 1 || aux_adentro == 1)
		cout << (N+1)/2 << "\n";
	else
		cout << "-1\n";
	return 0;
}
