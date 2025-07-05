#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lld;
lld t, numOnes, possible;
bool ans;

int main () {
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> numOnes;
		ans = 0;
		for(lld n = 1; n < 1000000; n++) {
			possible = sqrt((n * n) - numOnes);
			if(possible * possible == (n * n) - numOnes && possible > 0) {
				cout << n << " " << possible << "\n";
				ans = 1;
				break;
			}
		}
		if(!ans)
			cout << "-1\n";
	}
	return 0;
}
