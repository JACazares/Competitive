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

const int MAXN = (int)2e5 + 5;
int N, Q, a[MAXN], pre[MAXN], valid[MAXN];
int curr[MAXN];

vi S;
int roots[MAXN], ST[40*MAXN], lchild[40*MAXN], rchild[40*MAXN], tim = 1;

int build(int l = 1, int r = N)
{
	int aux = tim++;
	if(l == r)
	{
		ST[aux] = 0;
		return aux;
	}
	
	int mid = (l + r) / 2;
	lchild[aux] = build(l, mid);
	rchild[aux] = build(mid + 1, r);
	ST[aux] = 0;
	return aux;
}

int upd(int node, int pos, int x, int l = 1, int r = N)
{
	if(r < pos || pos < l)
		return node;
		
	int aux = tim++;
	if(l == r)
	{
		ST[aux] = x;
		return aux;
	}
	
	int mid = (l + r) / 2;
	lchild[aux] = upd(lchild[node], pos, x, l, mid);
	rchild[aux] = upd(rchild[node], pos, x, mid + 1, r);
	ST[aux] = ST[lchild[aux]] + ST[rchild[aux]];
	return aux;
}

int qry(int node, int L, int R, int l = 1, int r = N)
{
	if(R < l || r < L)
		return 0;
	if(L <= l && r <= R)
		return ST[node];
	int mid = (l + r) / 2;
	return qry(lchild[node], L, R, l, mid) + qry(rchild[node], L, R, mid + 1, r);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
		cin >> a[i];

	for(int i = 1; i <= N; i++)
	{
		pre[i] = pre[i - 1];
		while(!S.empty() && S.back() > a[i])
			S.pop_back();
		if(S.empty() || S.back() < a[i])
		{
			S.push_back(a[i]);
			pre[i]++;
			valid[i] = 1;
		}
	}
	
	roots[N + 1] = build();
	for(int i = N; i >= 1; i--)
	{
		int nxt = curr[a[i]];
		curr[a[i]] = i;
		
		roots[i] = roots[i + 1];
		if(nxt > 0 && !valid[nxt])
			roots[i] = upd(roots[i], nxt, 0);
		if(!valid[i])
			roots[i] = upd(roots[i], i, 1);
	}
	
	while(Q--)
	{
		int l, r;
		cin >> l >> r;
		
		int ans = pre[r] - pre[l - 1] + qry(roots[l], l, r);
		cout << ans << "\n";
	}
	return 0;
}
