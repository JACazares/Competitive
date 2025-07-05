#include <iostream>
using namespace std;
typedef long long int lld;
int ans;
string S;

int main () {
	cin >> S;
	for(int i = 0; i < S.length(); i++) {
		if(S[i] == '1' || S[i] == '3' || S[i] == '5' || S[i] == '7' || S[i] == '9')
			ans++;
		if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
