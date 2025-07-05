#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000;
int N, Max, Gato[MAXN+5], Visited[MAXN+5], x, y;
vector<int> Tree[MAXN+5];

int Solve(int n, int m)
{
	int Answer = 0;
	Visited[n] = 1;
	if(Gato[n] == 1)
		m++;
	else
		m = 0;
	if(m >= Max)
		return 0;
	for(int i=0; i<Tree[n].size(); i++)
	{
		if(!Visited[Tree[n][i]])
		{
			Answer += Solve(Tree[n][i], m);
		}
	}
	return Answer;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Max;
	for(int i=1; i<=N; i++)
		cin >> Gato[i];
	for(int i=1; i<N; i++)
	{
		cin >> x >> y;
		Tree[x].push_back(y);
		Tree[y].push_back(x);
	}
	cout << Solve(1, 0);
	return 0;
}
