#include <iostream>
using namespace std;
typedef long long int lld;
int N, ans;
char a, b;

int main () {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a;
		if(a == 'X')
			cin >> b >> b;
		else
			cin >> b >> a;
		if(b == '+') ans++;
		if(b == '-') ans--;
	}
	cout << ans << "\n";
	return 0;
}
