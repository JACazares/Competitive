#include <iostream>
using namespace std;
typedef long long int lld;
long double n, angle, pangle, adiff, minim, Interior, mini=999999;

int main () {
	cin >> n >> angle;
	Interior = 180*(n-2);
	Interior/= n;
	for(int i=1; i<=n-2; i++) {
		pangle = (Interior*i)/(n-2);
		adiff = pangle-angle;
		if(adiff < 0)
			adiff*= -1;
		if(adiff < mini)
			minim = i, mini = adiff;
	}
	cout << "2 1 " << 2+minim << "\n";
	return 0;
}