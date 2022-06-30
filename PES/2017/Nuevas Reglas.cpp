#include <iostream>
#include <algorithm>
#define MAXN 200000
#define mid ((left+right)/2)
#define lchild ((2*node))
#define rchild ((2*node)+1)
using namespace std;
typedef long long int lld;
struct segNode {
	bool check;
	int Left, Right;
};
int N, answerTable[MAXN+1];
segNode segTree[4*MAXN];
pair<int, int> a[MAXN], b[MAXN];

void updateSegTree(int node, int left, int right, int targetNode) {
	if(left == right) {
		segTree[node].check = 1;
		segTree[node].Left = 1;
		segTree[node].Right = 1;
		return;
	}
	if(mid < targetNode)
		updateSegTree(rchild, mid+1, right, targetNode);
	else
		updateSegTree(lchild, left, mid, targetNode);
	//cout << "Now Updating Node # " << left << ", " << right << " target was " << targetNode << "\n";
	segTree[node].check = segTree[lchild].check & segTree[rchild].check;
	int Union = segTree[lchild].Right+segTree[rchild].Left;
	if(segTree[lchild].check)
		segTree[node].Left = Union;
	else
		segTree[node].Left = segTree[lchild].Left;
	if(segTree[rchild].check)
		segTree[node].Right = Union;
	else
		segTree[node].Right = segTree[rchild].Right;
	for(int i=0; i<=Union; i++) {
		if(answerTable[Union-i] < a[targetNode].first)
			answerTable[Union-i] = a[targetNode].first;
		else
			break;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a[i].first;
		a[i].second = i;
		b[i] = a[i];
	}
	sort(b, b+N);
	for(int i=N-1; i>=0; i--)
		updateSegTree(1, 0, N-1, b[i].second);
	if(N == 1)
		answerTable[1] = a[0].first;
	for(int i=1; i<=N; i++)
		cout << answerTable[i] << " ";
	cout << "\n";
	return 0;
}
