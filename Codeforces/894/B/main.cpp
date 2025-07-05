#include <iostream>
#define MOD 1000000007
using namespace std;
long long int n, m, k;

long long int power(long long int A, long long int B) {
	long long int res=1;
	A%= MOD;
	while(B > 0) {
		if(B%2 == 1)
			res = (res*A)%MOD;
		B >>= 1;
		A = (A*A)%MOD;
	}
	return res;
}

int main() {
	cin >> n >> m >> k;
	if((n%2 != m%2) && k == -1)
		cout << "0";
	else {
		cout << power(power(2, (n-1)), (m-1)) << "\n";
	}
	return 0;
}
