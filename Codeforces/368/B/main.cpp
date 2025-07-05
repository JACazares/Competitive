#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long int lld;
int N, K, arr[MAXN], sufijo[MAXN], query;
bool cubeta[MAXN];

void precalculoSufijos() {
	for(int i = N-1; i >= 0; i--) {
		sufijo[i] = sufijo[i+1];
		if(cubeta[arr[i]] == 0)
			sufijo[i]++;
		cubeta[arr[i]] = 1;
	}
}

int main () {
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	precalculoSufijos();
	for(int i = 0; i < K; i++) {
		cin >> query;
		cout << sufijo[query-1] << "\n";
	}
	return 0;
}
