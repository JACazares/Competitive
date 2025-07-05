#include <iostream>
using namespace std;
typedef long long int lld;
int N, K, x, a, total=0;

int main () {
	cin >> N >> K >> x;
	for(int i = 0; i < N; i++) {
		cin >> a;
		if(i < N-K)
			total+= a;
		else
			total+= x;
	}
	cout << total << "\n";
	return 0;
}
