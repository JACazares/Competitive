#include <iostream>
using namespace std;
typedef long long int lld;
int N, cakeOne, cakeTwo, platesOne, platesTwo, ans = -(1<<30);

int main () {
	cin >> N >> cakeOne >> cakeTwo;
	for(int i = 1; i < N; i++) {
		platesOne = i;
		platesTwo = N-i;
		if(platesOne > 0 && platesTwo > 0)
			ans = max(ans, min(int(cakeOne/platesOne), int(cakeTwo/platesTwo)));
	}
	cout << ans << "\n";
	return 0;
}
