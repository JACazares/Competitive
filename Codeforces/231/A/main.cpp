#include <iostream>
using namespace std;
typedef long long int lld;
int N, aux, ans, a;

int main () {
	cin >> N;
	for(int i = 0; i < N; i++) {
		aux = 0;
		for(int j = 0; j < 3; j++) {
			cin >> a;
			aux+= a;
		}
		if(aux >= 2)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
