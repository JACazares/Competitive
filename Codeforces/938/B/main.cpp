#include <iostream>
using namespace std;
typedef long long int lld;
int N, pos, maxim = 1, minim = 1000000;

int main () {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> pos;
		if(pos <= 500000)
			maxim = max(maxim, pos);
		else
			minim = min(minim, pos);
	}
	cout << max(maxim - 1, 1000000 - minim) << "\n";
	return 0;
}
