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

const int MAXN = (int)1e5 + 5, INF = (1 << 30);
int N, F, a[MAXN], b[MAXN];
pii ST[4*MAXN];

pii comb(pii _a, pii _b)
{
	return (_a.first == _b.first ? _b : min(_a, _b));
}

void build(int node = 0, int l = 0, int r = N - 2)
{
	if(l == r)
	{
		ST[node] = {b[l], l};
		return;
	}
	
	int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	ST[node] = comb(ST[lchild], ST[rchild]);
}

pii qry(int L, int R, int node = 0, int l = 0, int r = N - 2)
{
	if(r < L || R < l)
		return {INF, 0};
	if(L <= l && r <= R)
		return ST[node];
		
	int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
	return comb(qry(L, R, lchild, l, mid), qry(L, R, rchild, mid + 1, r));
}

vpi tp;

int main()
{
	cin >> N >> F;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 0; i < N - 1; i++)
		b[i] = a[i + 1] - a[i];
	build();
	
	pii aux = {0, -1};
	while(aux.second + 1 <= N - 2)
	{
		aux = qry(aux.second + 1, N - 2);
		tp.pb(aux);
	}
	
	for(int f = 1; f < F; f++)
	{
		for(auto &i : tp)
			i.second -= 2;
			
		vpi tp2;
		
		if(tp[0].second >= 0)
		{
			aux = {0, -1};
			while(aux.second + 1 <= tp[0].second)
			{
				aux = qry(aux.second + 1, tp[0].second);
				aux.first += tp[0].first;
				tp2.pb(aux);
			}
		}

		for(int i = 1; i < sz(tp); i++)
		{
			if(tp[i].second >= 0)
			{
				aux = {0, tp[i - 1].second};
				while(aux.second + 1 <= tp[i].second)
				{
					aux = qry(aux.second + 1, tp[i].second);
					aux.first += tp[i].first;
					tp2.pb(aux);
				}
			}
		}
		
		swap(tp, tp2);
	}
	
	cout << tp[0].first << "\n";
	return 0;
}
