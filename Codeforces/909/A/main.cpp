#include <iostream>
using namespace std;
typedef long long int lld;
string firstName, lastName, ans;


int main () {
	cin >> firstName >> lastName;
	ans+= firstName[0];
	for(int i = 1; i < firstName.length(); i++) {
		if(firstName[i] >= lastName[0])
			break;
		ans+= firstName[i];
	}
	cout << ans << lastName[0] << "\n";
	return 0;
}
