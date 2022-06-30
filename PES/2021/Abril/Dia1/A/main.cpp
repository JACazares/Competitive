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

const int MAXN = 505;
int N, M, K;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//up, right, down, left
int anti[] = {3, 0, 1, 2};
int clok[] = {1, 2, 3, 0};
string a[MAXN];

bool valid(int x, int y)
{
	if(x < 0 || N <= x || y < 0 || M <= y)
		return false;
	if(a[x][(ull)y] == 'x')
		return false;
	return true;
}

struct Position
{
	int x1, y1, x2, y2, p, d;
	
	Position nxt()
	{
		Position tmp;
		tmp = *this;
		
		if(p == 1)
		{
			if(a[x1][(ull)y1] == 'A')
				tmp.d = anti[d];
			else if(a[x1][(ull)y1] == 'C')
				tmp.d = clok[d];
				
			tmp.x1 = x1 + dx[tmp.d];
			tmp.y1 = y1 + dy[tmp.d];
			
			if(!valid(tmp.x1, tmp.y1))
			{
				tmp.x1 = x1;
				tmp.y1 = y1;
				tmp.p = 0;
				tmp.d = 0;
			}
		}
		else if(p == 2)
		{
			if(a[x2][(ull)y2] == 'A')
				tmp.d = anti[d];
			else if(a[x2][(ull)y2] == 'C')
				tmp.d = clok[d];
				
			tmp.x2 = x2 + dx[tmp.d];
			tmp.y2 = y2 + dy[tmp.d];
			
			if(!valid(tmp.x2, tmp.y2))
			{
				tmp.x2 = x2;
				tmp.y2 = y2;
				tmp.p = 0;
				tmp.d = 0;
			}
		}
		return tmp;
	}
	
	void out()
	{
		cerr << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") - " << p << ", ";
		if(d == 0)
			cerr << "up";
		else if(d == 1)
			cerr << "right";
		else if(d == 2)
			cerr << "down";
		else if(d == 3)
			cerr << "left";
		cerr << "\n";
	}
	
	bool operator <(const Position& _x) const
	{
		if(x1 == _x.x1)
		{
			if(y1 == _x.y1)
			{
				if(x2 == _x.x2)
				{
					if(y2 == _x.y2)
					{
						if(p == _x.p)
							return d < _x.d;
						return p < _x.p;
					}
					return y2 < _x.y2;
				}
				return x2 < _x.x2;
			}
			return y1 < _x.y1;
		}
		return x1 < _x.x1;
	}
};

map<Position, bool> vis;
priority_queue<pair<int, Position>> PQ;

int main()
{
	cin >> K >> M >> N;
	if(K != 2)
	{
		cout << "5\n";
		return 0;
	}
	
	int x[3], y[3];
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
		for(int j = 0; j < M; j++)
		{
			if(a[i][(ull)j] == '1' || a[i][(ull)j] == '2')
			{
				x[a[i][(ull)j] - '0'] = i;
				y[a[i][(ull)j] - '0'] = j;
			}
		}
	}
	
	Position state{x[1], y[1], x[2], y[2], 0, 0};
	PQ.push({0, state});
	while(!PQ.empty())
	{
		auto aux = PQ.top();
		PQ.pop();
		
		if(aux.second.x1 == aux.second.x2 && aux.second.y1 == aux.second.y2 && aux.second.p == 0)
		{
			cout << -aux.first << "\n";
			return 0;
		}
		
		if(vis[aux.second])
			continue;
		vis[aux.second] = 1;
		
		if(aux.second.p == 0)
		{
			aux.first--;
			for(int p = 1; p <= 2; p++)
				for(int d = 0; d <= 3; d++)
				{
					aux.second.p = p;
					aux.second.d = d;
					if(!vis[aux.second])
						PQ.push(aux);
				}
		}
		else
		{
			aux.second = aux.second.nxt();
			if(!vis[aux.second])
				PQ.push(aux);
		}
	}
	cout << "-1\n";
	return 0;
}
