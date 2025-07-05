#include <iostream>
using namespace std;
typedef long long int lld;
string S;
int Left, Right, mid, ans, bucket[26];
bool val;

bool solve(int x) {
	for(int c = 0; c < 26; c++) {
		for(int i = 0; i < 26; i++)
			bucket[i] = 0;
		for(int i = 0; i < S.length(); i++) {
			bucket[S[i]-'a']++;
			if(i - x >= 0) {
				if(!bucket[c])
					break;
				bucket[S[i-x]-'a']--;
			}
			if(i == S.length()-1)
				return true;
		}
	}
	return false;
}

int main () {
	cin >> S;
	Left = 0, Right = S.length() - 1;
	while(Left <= Right) {
		mid = (Left + Right)/2;
		val = solve(mid);
		if(val)
			ans = mid, Right = mid - 1;
		else
			Left = mid + 1;
	}
	cout << ans+1 << "\n";
	return 0;
}
