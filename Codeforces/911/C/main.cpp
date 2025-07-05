#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lld;
int k[3], aux;
bool ans, res;

int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return (a*b)/(gcd(a, b));
}

int main () {
	cin >> k[0] >> k[1] >> k[2];
	sort(k, k+3);
	res = 0;
	do {
		aux = 0;
		ans = 0;
		for(int i = 0; i <= lcm(k[0], lcm(k[1]+1, k[2])); i++) {
			if(i == lcm(k[0], lcm(k[1], k[2])))
				ans = 1;
			if(i%k[0] == 0 && (i+1)%k[1] == 0 && (i+aux)%k[2] == 0) {
				ans = 1;
				break;
			}
			if(i%k[0] == 0 || (i+1)%k[1] == 0 || (i+aux)%k[2] == 0)
				continue;
			if(aux == 0) {
				aux = k[2] - (i % k[2]);
			} else {
				ans = 0;
				break;
			}
		}
		if(ans) {
			res = 1;
			break;
		}
	} while(next_permutation(k, k+3));
	if(res)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
