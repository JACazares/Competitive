#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lld;
int N, K, a[55], cnt;

int main () {
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		if(((i < K) || (i >= K && a[i] == a[K-1])) && a[i] > 0)
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
