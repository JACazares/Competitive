#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long int lld;
lld N, a[MAXN], Left = -1, Right = -1, minim = (1<<30), ans = (1<<30);

int main () {
	cin >> N;
	for(int i=0; i < N; i++) {
		cin >> a[i];
		minim = min(a[i], minim);
	}
	for(int i = 0; i < N; i++) {
		if(a[i] == minim)
			Left = Right, Right = i;
		if(Left > -1 && Right > -1)
			ans = min(ans, Right-Left);
	}
	cout << ans << "\n";
	return 0;
}
