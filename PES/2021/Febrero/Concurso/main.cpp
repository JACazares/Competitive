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

const int MAXN = 1e5 + 5;
int N, M, padre[MAXN];
ll r[MAXN], p[MAXN], best[MAXN];
vi Graph[MAXN], ratings;
multiset<int> child[MAXN];

void upd(int node)
{
    ratings.pb(r[node]);
    for(auto i : Graph[node])
        upd(i);
}

void dfs(int node)
{
	int bigSz = 0, bigChild = 0;
    for(auto i : Graph[node])
	{
        dfs(i);
		if(child[i].size() > bigSz)
		{
			bigSz = child[i].size();
			bigChild = i;
		}
	}

	if(Graph[node].empty())
	{
		child[node].insert(r[node]);
		if(r[node] <= M)
			best[node] = p[node];
		return;
	}

	swap(child[node], child[bigChild]);
	child[node].insert(r[node]);
	for(auto i : Graph[node])
	{
		if(i == bigChild)
			continue;
		for(auto j : child[i])
			child[node].insert(j);
	}

	ll sum = 0;
	for(auto i : child[node])
	{
		if(sum + i <= M)
		{
			best[node]++;
			sum += i;
		}
		else
			break;
	}
	best[node] *= p[node];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int root = 1;
    for(int i = 1; i <= N; i++)
    {
        cin >> padre[i] >> r[i] >> p[i];
        if(padre[i] == 0)
            root = i;
        else
            Graph[padre[i]].pb(i);
    }
    
    dfs(root);
    ll ans = 0;
    for(int i = 1; i <= N; i++)
        ans = max(ans, best[i]);
    cout << ans << "\n";
    return 0;
}
