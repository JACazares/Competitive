#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lld;
double n;

int main () {
	cin >> n;
	cout << ((ceil(n/2)*(ceil(n/2)+1))/2)+((floor(n/2)*(floor(n/2)+1))/2) << "\n";
	return 0;
}
