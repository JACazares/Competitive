#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lld;
lld n, m;


int main () {
	cin >> n >> m;
	if(log2(m) < n)
		cout << m << "\n";
	else
		cout << m % int(pow(2, n)) << "\n";
	return 0;
}
