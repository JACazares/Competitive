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
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = (int)1e5 + 5;
int W, H, N, vis[MAXN];
vector<pii> edge[4];

int main()
{
	cin >> W >> H;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if(x1 == 0 && x2 == W)
		{
			edge[3].pb({y1, i});
			edge[1].pb({y2, i});
		}
		else if(x1 == W && x2 == 0)
		{
			edge[1].pb({y1, i});
			edge[3].pb({y2, i});
		}
		else if(y1 == 0 && y2 == H)
		{
			edge[2].pb({x1, i});
			edge[0].pb({x2, i});
		}
		else if(y1 == H && y2 == 0)
		{
			edge[0].pb({x1, i});
			edge[2].pb({x2, i});
		}
	}
	
	sort(all(edge[0]));
	sort(all(edge[1]));
	reverse(all(edge[1]));
	sort(all(edge[2]));
	reverse(all(edge[2]));
	sort(all(edge[3]));
	
	bool ans = 1;
	stack<int> S;
	
	for(int k = 0; k < 4; k++)
	for(auto i : edge[k])
	{
		if(!vis[i.second])
		{
			S.push(i.second);
			vis[i.second] = 1;
		}
		else
		{
			if(S.empty() || S.top() != i.second)
			{
				ans = 0;
				break;
			}
			else
				S.pop();
		}
	}

	cout << (ans ? "Y" : "N") << "\n";
	return 0;
}
