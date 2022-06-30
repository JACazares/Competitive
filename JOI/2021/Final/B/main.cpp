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
const ll INF = (1LL << 62LL);
int N, Q;
ll a[MAXN], W[MAXN];
pair<ll, int> spacesL[MAXN], spacesR[MAXN];

ll l[MAXN], r[MAXN], pos;
ll finalL[MAXN], finalR[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	a[0] = -INF, a[N + 1] = INF;
	for(int i = 0; i <= N + 1; i++)
	{
		if(i < N + 1)
			spacesR[i] = {a[i + 1] - a[i], i};
		else
			spacesR[i] = {0, N + 1};
			
		if(i > 0)
			spacesL[i] = {a[i] - a[i - 1], i};
		else
			spacesL[i] = {0, 0};
	}
	sort(spacesR, spacesR + N + 2);
	sort(spacesL, spacesL + N + 2);
	
	ll delta = 0;
	int lpnt = 0, rpnt = 0;
	for(int q = 1; q <= Q; q++)
	{
		cin >> W[q];
		pos += W[q];
		l[q] = min(l[q - 1], pos);
		r[q] = max(r[q - 1], pos);
		
		if(l[q] < l[q - 1])
		{
			//cerr << l[q] << " " << r[q] << "\n";
			delta += l[q - 1] - l[q];
			
			for(; lpnt <= N + 1; lpnt++)
			{
				if(spacesL[lpnt].second == 0)
					continue;
				if(spacesL[lpnt].first > delta)
					break;
				int idx = spacesL[lpnt].second;
				finalL[idx] = a[idx] + l[q - 1] - (spacesL[lpnt].first - (delta - l[q - 1] + l[q]));
				//cerr << "l " << idx << ": " << finalL[idx] << "\n";
			}
			
			for(; rpnt <= N + 1; rpnt++)
			{
				if(spacesR[rpnt].second == N + 1)
					continue;
				if(spacesR[rpnt].first > delta)
					break;
				int idx = spacesR[rpnt].second;
				finalR[idx] = a[idx] + r[q - 1];
				//cerr << "r " << idx << ": " << finalR[idx] << "\n";
			}
			
		}
		else if(r[q] > r[q - 1])
		{
			//cerr << l[q] << " " << r[q] << "\n";
			delta += r[q] - r[q - 1];

			for(; lpnt <= N + 1; lpnt++)
			{
				if(spacesL[lpnt].second == 0)
					continue;
				if(spacesL[lpnt].first > delta)
					break;
				int idx = spacesL[lpnt].second;
				finalL[idx] = a[idx] + l[q - 1];
				//cerr << "l " << idx << ": " << finalL[idx] << "\n";
			}
			
			for(; rpnt <= N + 1; rpnt++)
			{
				if(spacesR[rpnt].second == N + 1)
					continue;
				if(spacesR[rpnt].first > delta)
					break;
				int idx = spacesR[rpnt].second;
				finalR[idx] = a[idx] + r[q - 1] + (spacesR[rpnt].first - (delta - r[q] + r[q - 1]));
				//cerr << "r " << idx << ": " << finalR[idx] << "\n";
			}	
		}
	}
	
	for(int i = lpnt; i <= N + 1; i++)
	{
		int idx = spacesL[i].second;
		finalL[idx] = a[idx] + l[Q];
	}
	for(int i = rpnt; i <= N + 1; i++)
	{
		int idx = spacesR[i].second;
		finalR[idx] = a[idx] + r[Q];
	}
	
	for(int i = 1; i <= N; i++)
		cout << finalR[i] - finalL[i] << "\n";
	return 0;
}
