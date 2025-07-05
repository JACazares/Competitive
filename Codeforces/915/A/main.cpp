#include <iostream>
using namespace std;
typedef long long int lld;
int N, K, a, ans = (1 << 30);

int main () {
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> a;
		if(K % a == 0)
			ans = min(ans, K / a);
	}
	cout << ans << "\n";
	return 0;
}
