#include "candies.h"
#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pii>;

struct Node
{
	ll val, maxim, minim;
};

const int MAXN = (int)2e5 + 5, MAXQ = (int)2e5 + 5;
const ll INF = (1LL << 62LL);
int N, Q;
vi c, v, ans;
vpi in[MAXQ], out[MAXQ];
Node ST[4*MAXN];
ll lazy[4*MAXN];

Node comb(Node a, Node b)
{
	Node tmp;
	tmp.val = 0;
	tmp.maxim = max(a.maxim, b.maxim);
	tmp.minim = min(a.minim, b.minim);
	return tmp;
}

/*
path/ST	- peaks and valleys array (stored using a ST)
in/out	- all in's and out's of updates, store an in in L and an out in R
		 -stores the value and the time (index) of the update
*/

void propagate(int node, int l, int r)
{
	ST[node].minim += lazy[node];
	ST[node].maxim += lazy[node];
	if(l == r)
		ST[node].val += lazy[node];
	else
	{
		int lchild = 2*node + 1, rchild = 2*node + 2;
		lazy[lchild] += lazy[node];
		lazy[rchild] += lazy[node];
	}
	lazy[node] = 0;
}

void upd(int L, int R, int val, int node = 0, int l = 0, int r = N)
{
	propagate(node, l, r);
	if(R < l || r < L)
		return;
	if(L <= l && r <= R)
	{
		lazy[node] = val;
		propagate(node, l, r);
		return;
	}
	
	int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
	upd(L, R, val, lchild, l, mid);
	upd(L, R, val, rchild, mid + 1, r);
	ST[node] = comb(ST[lchild], ST[rchild]);
}

Node qry(int L, int R, int node = 0, int l = 0, int r = N)
{
	propagate(node, l, r);
	if(r < L || R < l)
		return Node{0, -INF, INF};
	if(L <= l && r <= R)
		return ST[node];
	
	int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
	return comb(qry(L, R, lchild, l, mid), qry(L, R, rchild, mid + 1, r));
}

int solve(int C)
{
	int s = 0, e = N, mid, ans = 0;
	Node val;
	while(s <= e)
	{
		mid = (s+e)/2;
		val = qry(mid, N);
		
		if(val.maxim-val.minim > C)
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	
	val = qry(ans, N);
	int aux = qry(N, N).maxim;
	int aux1 = qry(ans, ans).maxim, aux2 = qry(ans+1, ans+1).maxim;
	//cerr << ans << ": " << aux1 << ", " << aux2 << ", " << aux << "\n";
	if(val.maxim-val.minim >= C && aux2 > aux1)
		return aux - (val.maxim - C);
	else
		return aux - val.minim;
}

vi distribute_candies(vi _c, vi _l, vi _r, vi _v)
{
    N = sz(_c);
	Q = sz(_l);
	swap(c, _c);
	swap(v, _v);
	vi ans(N, 0);
	
	for(int i = 0; i < Q; i++)
	{
		in[_l[i]].pb(pii{i + 1, v[i]});
		out[_r[i]].pb(pii{i + 1, -v[i]});
	}

	for(int i = 0; i < N; i++)
	{
		for(auto x : in[i])
			upd(x.first, N, x.second);
		/*
		for(int x = 0; x <= N; x++)
			cout << qry(x, x).maxim << " ";
		cout << "\n";
		for(int x = 0; x <= N; x++)
			cout << qry(x, x).minim << " ";
		cout << "\n";*/
		ans[i] = solve(c[i]);
		//cout << "\n";
		for(auto x : out[i])
			upd(x.first, N, x.second);
	}
    return ans;
}
