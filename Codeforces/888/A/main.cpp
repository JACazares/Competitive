#include <iostream>
#define MAXN 1000
using namespace std;
typedef long long int lld;
int N, a[MAXN], ans;

int main () {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];
	for(int i=1; i<N-1; i++)
		if((a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1]))
			ans++;
	cout << ans << '\n';
	return 0;
}
