#include <iostream>
using namespace std;
typedef long long int lld;
int N, K, a, prefix[150000], minHeight=9999999, ans;

int main () {
	cin >> N >> K;
	for(int i=0; i<N; i++) {
		cin >> a;
		if(i == 0)
			prefix[i] = a;
		else
			prefix[i] = prefix[i-1]+a;
	}
	for(int i=K-1; i<N; i++) {
		if(i-K < 0)
			minHeight = prefix[i], ans = 1;
		else if(minHeight > prefix[i] - prefix[i-K])
			minHeight = prefix[i] - prefix[i-K], ans = i-K+2;
	}
	cout << ans << "\n";
	return 0;
}
