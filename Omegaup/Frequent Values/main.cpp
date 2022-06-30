#include <iostream>
#define MAXN 100000
#define INF 999999
using namespace std;
struct arrayN {
	int num, lindex, rindex;
};
int N, K, n, Array[MAXN], Start[MAXN], End[MAXN];
bool Leaf[4*MAXN];
arrayN MergedArray[MAXN];
arrayN Tree[4*MAXN];

void Merge() {
	MergedArray[n].lindex = 0;
	for(int i=1; i<N; i++) {
		if(Array[i] != Array[i-1]) {
			MergedArray[n].num = Array[i-1];
			MergedArray[n++].rindex = i-1;
			MergedArray[n].lindex = i;
		}
	}
	MergedArray[n].num = Array[N-1];
	MergedArray[n++].rindex = N-1;
}

void Create(int l, int r, int node) {
	if(l == r) {
		Tree[node].num = MergedArray[r].rindex - MergedArray[l].lindex + 1;
		Tree[node].lindex = MergedArray[l].lindex;
		Tree[node].rindex = MergedArray[r].rindex;
		Leaf[node] = 1;
		return;
	}
	int mid = (l+r)/2;
	int lchild = (2*node)+1;
	int rchild = (2*node)+2;
	Create(l, mid, lchild);
	Create(mid+1, r, rchild);
	Tree[node].num = max(Tree[lchild].num, Tree[rchild].num);
	Tree[node].lindex = Tree[lchild].lindex;
	Tree[node].rindex = Tree[rchild].rindex;
}

int Query(int i, int j, int node) {
	int l = Tree[node].lindex;
	int r = Tree[node].rindex;
	if(r < i || l > j)
		return -INF;
	if(l >= i && r <= j)
		return Tree[node].num;
	if(Leaf[node]) {
		if(i >= l && i <= r && j > r)
			return r-i+1;
		if(j >= l && j <= r && i < l)
			return j-l+1;
		if(i >= l && j <= r)
			return j-i+1;
	}
	int lchild = (2*node)+1;
	int rchild = (2*node)+2;
	return max(Query(i, j, lchild), Query(i, j, rchild));
}

int main() {
	cin >> N >> K;
	for(int i=0; i<N; i++)
		cin >> Array[i];
	for(int i=0; i<K; i++)
		cin >> Start[i] >> End[i];
	Merge();
	Create(0, n-1, 0);
	for(int i=0; i<K; i++)
		cout << Query(Start[i]-1, End[i]-1, 0) << "\n";
	return 0;
}
