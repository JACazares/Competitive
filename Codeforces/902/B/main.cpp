#include <iostream>
#include <vector>
#define MAXN 10005
using namespace std;
typedef long long int lld;
int N, v, color[MAXN], ans;
bool visited[MAXN];
vector<int> Graph[MAXN];

int DFS(int node, int colorParent) {
	visited[node] = 1;
	int ret = 0;
	for(int i = 0; i < Graph[node].size(); i++)
		if(!visited[Graph[node][i]])
			ret+= DFS(Graph[node][i], color[node]);
	if(color[node] != colorParent)
		ret++;
	return ret;
}

int main () {
	cin >> N;
	for(int i = 1; i <= N - 1; i++) {
		cin >> v;
		Graph[i+1].push_back(v);
		Graph[v].push_back(i+1);
	}
	for(int i = 1; i <= N; i++)
		cin >> color[i];

	ans = DFS(1, 0);

	cout << ans << "\n";
	return 0;
}
