#include <iostream>
#include <stack>
#define MAXN 300000
using namespace std;
typedef long long int lld;
lld N, K, a[MAXN], bucket[MAXN], b[MAXN], ind, maxim, aux;
lld S[MAXN], StackInd;

bool Empty() {
	if(StackInd == 0)
		return true;
	return false;
}

int Top() {
	return S[StackInd-1];
}

void Push(lld val) {
	S[StackInd++] = val;
}

void Pop() {
	StackInd--;
}

int main () {
	cin >> N >> K;
	a[N] = 0;
	for(int i = 0; i < K; i++) {
		cin >> a[i];
		bucket[a[i]] = 1;
		maxim = max(maxim, a[i]);
	}
	aux = K;
	for(lld j = maxim; j > 0; j--) {
		if(!bucket[j])
			a[aux++] = j;
	}
	for(lld j = N; j > maxim; j--) {
		if(!bucket[j])
			a[aux++] = j;
	}
	for(int i = 0; i <= N; i++) {
		if(Empty() || Top() > a[i])
			Push(a[i]);
		else {
			while(!Empty() && Top() < a[i]) {
				b[++ind] = Top();
				if(ind != b[ind]) {
					cout << "-1\n";
					return 0;
				}
				Pop();
			}
			Push(a[i]);
		}
	}
	for(int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}
