#include <iostream>
#include <algorithm>
#define MAXN 100005
#define mp make_pair
using namespace std;
int N, a[MAXN], deseado[MAXN], ans, ans2;
pair<int, int> A[MAXN];
bool visited[MAXN];

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.first < y.first;
}

bool cmp2(pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}

int dfs(int startNode, int node) {
	visited[node] = 1;
	if(startNode == node)
		return 1;
	return dfs(startNode, deseado[node]) + (a[node] != a[deseado[node]]);
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		A[i] = mp(a[i], i);
	}

	sort(A+1, A+N+1, cmp);

	for(int i = 1; i <= N; i++) {
		deseado[A[i].second] = i;
	}
		
	for(int i = 1; i <= N; i++) {
		if(!visited[i]) {
			ans+= (dfs(i, deseado[i]) - 1);
			if(i != deseado[i] && a[i] == a[deseado[i]])
				ans--;
		}
	}

	sort(A+1, A+N+1, cmp2);


	for(int i = 1; i <= N; i++) {
		deseado[A[i].second] = i;
		visited[i] = 0;
	}
		
	for(int i = 1; i <= N; i++) {
		if(!visited[i]) {
			ans2+= (dfs(i, deseado[i]) - 1);
			if(i != deseado[i] && a[i] == a[deseado[i]])
				ans2--;
		}
	}


	cout << min(ans, ans2) << "\n";

	return 0;
}
