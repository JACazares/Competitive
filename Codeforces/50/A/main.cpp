#include <iostream>
using namespace std;
typedef long long int lld;
lld N, M;

int main () {
	cin >> M >> N;
	if(M % 2 == 0)
		cout << (M * N) / 2;
	else {
		if(N % 2 == 0)
			cout << (M * N) / 2;
		else
			cout << ((M * (N - 1)) / 2) + (M / 2);
	}
	cout << "\n";
	return 0;
}
