#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100005
using namespace std;
int N, color[MAXN], rootNode, u, v, aux, possible;
vector<int> Graph[MAXN];
queue<int> Q;
bool visited[MAXN], ans = true, visited2[MAXN];

int checkRoot() {
	for(int i = 1; i <= N; i++)
		if(Graph[i].size() == 1)
			Q.push(i);
	
	int node = 0, nextNode = 0;
	while(!Q.empty()) {
		node = Q.front();
		Q.pop();
		for(int i = 0; i < Graph[node].size(); i++) {
			nextNode = Graph[node][i];
			if(visited[nextNode] && color[nextNode] != color[node])
				return nextNode;

			else if(!visited[nextNode]) {
				if(color[nextNode] != color[node])
					return nextNode;
				visited[nextNode] = 1;
				Q.push(nextNode);
			}
		}
	}

	return 1;
}

bool checkTree(int node, int Color) {

	if(color[node] != Color)
		return false;

	int nextNode = 0;
	for(int i = 0; i < Graph[node].size(); i++) {
		nextNode = Graph[node][i];
		if(!visited2[nextNode]) {
			visited2[nextNode] = 1;
			if(!checkTree(nextNode, Color))
				return false;
		}
	}

	return true;
}

int main() {
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
	for(int i = 1; i <= N; i++)
		cin >> color[i];

	rootNode = checkRoot();
    visited2[rootNode] = 1;

	int nextNode = 0;
	for(int i = 0; i < Graph[rootNode].size(); i++) {
		nextNode = Graph[rootNode][i];
		if(!checkTree(nextNode, color[nextNode]))
			ans = 0;
	}

    if(ans == 0 || rootNode == 0) {
    	possible = color[1];
    	for(int i = 1; i <= N; i++) {
    		if(color[i] != possible)
    			aux++, rootNode = i;
    	}
    	if(aux == 1) {
    		ans = 1;
    	} else {
    		possible = color[1];
    		for(int i = 1; i <= N; i++) {
    			if(color[i] != possible)
    				aux++, rootNode = i;
    		}
    		if(aux == 1)
    			ans = 1;
    	}
    }

	
	if(ans)
		cout << "YES\n" << rootNode << "\n";
	else
		cout << "NO\n";
	return 0;
}
