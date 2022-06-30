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

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Node
{
	int val, freq, sz;
	unsigned int p;
	Node *l, *r;
	
	Node(int _x)
	{
		val = _x;
		freq = 1;
		sz = 1;
		p = 0;
		l = nullptr;
		r = nullptr;
	}
};

typedef Node* pNode;

int getSz(pNode node)
{
	if(!node)
		return 0;
	return node -> sz;
}

void updSz(pNode node)
{
	if(!node)
		return;
	node -> sz = getSz(node -> l) + getSz(node -> r) + node -> freq;
}

void split(pNode node, int k, pNode& l, pNode& r)
{
	if(!node)
	{
		l = nullptr;
		r = nullptr;
		return;
	}
	
	if(node -> val <= k)
	{
		l = node;
		split(l -> r, k, l -> r, r);
		updSz(l);
	}
	else
	{
		r = node;
		split(r -> l, k, l, r -> l);
		updSz(r);
	}
}

void merge(pNode l, pNode r, pNode& tree)
{
	if(!l && !r)
	{
		tree = nullptr;
		return;
	}
	else if(!l)
	{
		tree = r;
		updSz(tree);
		return;
	}
	else if(!r)
	{
		tree = l;
		updSz(tree);
		return;
	}
	
	if(l -> p > r -> p)
	{
		merge(l -> r, r, l -> r);
		tree = l;
	}
	else
	{
		merge(l, r -> l, r -> l);
		tree = r;
	}
	updSz(tree);
}

void ins(int x, pNode& node)
{
	pNode l;
	pNode r;
	pNode tmpL;
	pNode tmp;
	
	split(node, x, l, r);
	split(l, x - 1, tmpL, tmp);
	if(!tmp)
	{
		tmp = new Node(x);
		tmp -> p = gen();
	}
	else
	{
		tmp -> freq++;
		tmp -> sz++;
	}
	merge(tmpL, tmp, l);
	merge(l, r, node);
}

void del(int x, pNode& node)
{
	pNode l;
	pNode r;
	pNode tmpL;
	pNode tmp;
	
	split(node, x, l, r);
	split(l, x - 1, tmpL, tmp);
	if(!tmp)
		merge(tmpL, r, node);
	else
	{
		tmp -> freq--;
		tmp -> sz--;
		if(tmp -> freq == 0)
		{
			delete(tmp);
			merge(tmpL, r, node);
		}
		else
		{
			merge(tmpL, tmp, l);
			merge(l, r, node);
		}
	}
}

void out(pNode node)
{
	if(!node)
		return;
	out(node -> l);
	cerr << node -> val << " ";
	out(node -> r);
}

const int MAXN = (int)4e5 + 5;
int N, t, a[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> t;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	
	if(t == 1)
	{
		//minimum
		Node *L = nullptr, *R = nullptr;
		for(int i = 0; i < N; i++)
			ins(a[i] + i, R);
		
		int ans = 0;
		for(int i = 0; i < N; i++)
		{
			del(a[i] + i, R);
			
			ans = 0;
			pNode tmpL;
			pNode tmpR;
			tmpL = tmpR = nullptr;
			split(L, a[i] - i - 1, tmpL, tmpR);
			ans += getSz(tmpL);
			merge(tmpL, tmpR, L);
			
			tmpL = tmpR = nullptr;
			split(R, a[i] + i - 1, tmpL, tmpR);
			//out(R);
			//cerr << "\n";
			ans += getSz(tmpL);
			merge(tmpL, tmpR, R);
			
			ins(a[i] - i, L);
			
			ans++;
			cout << ans << "\n";
		}
	}
	else
	{
		//maximum
		for(int i = 0; i < N; i++)
		{
			int x = 0, aux = 0, ans = 0;
			for(int l = i, r = i; l >= 0 || r < N; l--, r++)
			{
				if(l == 0 || r == N - 1)
				{
					aux = 0;
					for(int k = 0; k <= l; k++)
						if(a[k] < a[i] + x)
							aux++;

					for(int k = r; k < N; k++)
						if(a[k] < a[i] + x)
							aux++;
					
					if(l >= 0 && r < N)
					{
						for(int k = l + 1; k < i; k++)
							if(a[k] + (k - l) < a[i] + x)
								aux++;
						
						for(int k = r - 1; k > i; k--)
							if(a[k] + (r - k) < a[i] + x)
								aux++;
					}
					else if(r < N)
					{
						for(int k = r - 1; k >= 0; k--)
							if(a[k] + (r - k) < a[i] + x)
								aux++;
					}
					else if(l >= 0)
					{
						for(int k = l + 1; k < N; k++)
							if(a[k] + (k - l) < a[i] + x)
								aux++;
					}
					
					ans = max(ans, aux + 1);
				}
				x++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

