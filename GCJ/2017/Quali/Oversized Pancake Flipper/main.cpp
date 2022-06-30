#include <iostream>
#include <cstring>
using namespace std;
typedef long long int lld;
int T, k;
string S;

int main () {
	cin >> T;
	for(int j=1; j<=T; j++) {
		cin >> S >> k;
		int rc=0, arr[1002], nflips=0, ans=1;
		memset(arr, 0, sizeof(arr));
		for(int i=S.length()-1; i>=0; i--) {
			rc+= arr[i];
			if(rc%2 == 1) {
				if(S[i] == '-') S[i] = '+';
				else	S[i] = '-';
			}
			if(i-k >= -1) {
				if(S[i] == '-') {
					nflips++;
					rc++;
					S[i] = '+';
					arr[i-k] = -1;
				}
			}
		}
		for(int i=0; i<S.length(); i++) {
			if(S[i] == '-') {
				ans = 0;
				break;
			}
		}
		cout << "Case #" << j << ": ";
		if(ans)
			cout << nflips << "\n";
		else
			cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}
