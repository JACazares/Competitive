#include <iostream>
#define MAXN 100005
using namespace std;
long long N, a, bucket[MAXN], dp[MAXN], maxim;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a;
		bucket[a]++;
		maxim = max(a, maxim);
	}
	dp[1] = bucket[1];
	for(int i = 2; i <= maxim; i++)
		dp[i] = max(dp[i-1], dp[i-2] + (i * bucket[i]));
	cout << dp[maxim] << "\n";
	return 0;
}
