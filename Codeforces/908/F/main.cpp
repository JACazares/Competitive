#include <iostream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define MAXN 300010
using namespace std;
typedef long long int lld;
struct Nodes {
	lld dist;
	char color;
};
lld N, Prev, firstNode, secondNode, ans, Parent[MAXN];
Nodes node[MAXN];
vector<pair<lld, lld> > Edges;

lld Find(lld nodeOne) {
	if(Parent[nodeOne] == nodeOne)
		return nodeOne;
	return Parent[nodeOne] = Find(Parent[nodeOne]);
}

void Union(lld nodeOne, lld nodeTwo) { Parent[Find(nodeOne)] = Find(nodeTwo); }

bool cmp(pair<lld, lld> A, pair<lld, lld> B) {
	return abs(node[A.first].dist - node[A.second].dist) < abs(node[B.first].dist - node[B.second].dist);
}

bool cmp2(Nodes A, Nodes B) {
	return A.dist < B.dist;
}

int main () {
	cin >> N;
	for(lld i = 0; i < N; i++) {
		cin >> node[i].dist >> node[i].color;
		Parent[i] = i+1;
	}
	sort(node, node+N, cmp2);
	//Green - Green
	Prev = -1;
	for(lld i = 0; i < N; i++) {
		if(node[i].color == 'G') {
			if(Prev > -1) {
				Union(Prev, i);
				ans+= abs(node[Prev].dist - node[i].dist);
			}
			Prev = i;
		}
	}
	//Green - Blue // Blue - Green // Blue - Blue
	Prev = -1;
	for(lld i = 0; i < N; i++) {
		if(node[i].color == 'G' || node[i].color == 'B') {
			if(Prev > -1)
				if(!(node[i].color == 'G' && node[Prev].color == 'G'))
					Edges.push_back(mp(Prev, i));
			Prev = i;
		}
	}
	//Green - Red // Red - Green // Red - Red
	Prev = -1;
	for(lld i = 0; i < N; i++) {
		if(node[i].color == 'G' || node[i].color == 'R') {
			if(Prev > -1)
				if(!(node[i].color == 'G' && node[Prev].color == 'G'))
					Edges.push_back(mp(Prev, i));
			Prev = i;
		}
	}

	sort(Edges.begin(), Edges.end(), cmp);

	for(lld i = 0; i < Edges.size(); i++) {
		firstNode = Edges[i].first;
		secondNode = Edges[i].second;
		if(node[firstNode].color == 'G' && node[secondNode].color == 'G') {
			Union(firstNode, secondNode);
			ans+= abs(node[firstNode].dist - node[secondNode].dist);
		} else {
			if(Find(firstNode) != Find(secondNode)) {
				Union(firstNode, secondNode);
				ans+= abs(node[firstNode].dist - node[secondNode].dist);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
