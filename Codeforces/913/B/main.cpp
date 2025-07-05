#include <iostream>
#include <vector>
#define MAXN 1005
using namespace std;
typedef long long int lld;
int N, parent[MAXN];
bool ans = 1;
vector<int> Tree[MAXN];

bool DFS(int node) {
	if(Tree[node].size() == 0)
		return 1;
	int ret = 0;
	for(int i = 0; i < Tree[node].size(); i++) {
		ret+= DFS(Tree[node][i]);
	}
	if(ret < 3)
		ans = 0;
	return 0;
}

int main () {
	cin >> N;
	for(int i = 2; i <= N; i++) {
		cin >> parent[i];
		Tree[parent[i]].push_back(i);
	}
	DFS(1);
	if(ans)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
