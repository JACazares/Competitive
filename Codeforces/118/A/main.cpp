#include <iostream>
#include <cctype>
using namespace std;
typedef long long int lld;
string S;

int main () {
	cin >> S;
	for(int i = 0; i < S.length(); i++) {
		S[i] = tolower(S[i]);
		if(S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u' && S[i] != 'y')
			cout << "." << S[i];
	}
	cout << "\n";
	return 0;
}
