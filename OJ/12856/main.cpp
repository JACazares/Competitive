/*Counting substhreengs*/
#include <iostream>
#define MAXN 1000000
using namespace std;
typedef long long int lld;
string s;
int prefix[MAXN+5], DS[3];
lld res;

void calculatePrefix() {
	prefix[0] = -1;
	for(int i=1; i<=s.length(); i++) {
		if(s[i-1] < '0' || s[i-1] > '9')
			prefix[i] = -1;
		else if(prefix[i-1] == -1 && s[i-1] >= '0' && s[i-1] <= '9')
			prefix[i] = s[i-1]-'0';
		else
			prefix[i] = prefix[i-1] + (s[i-1]-'0');
	}
}

int main() {
	while(cin >> s) {
		calculatePrefix();
		for(int i=1; i<=s.length(); i++)
		    if(prefix[i] > -1)	prefix[i]%= 3;
		for(int i=0; i<=s.length(); i++) {
			if(prefix[i] == -1) {
				DS[0] = 1;
				DS[1] = 0;
				DS[2] = 0;
			} else {
				res+= DS[prefix[i]];
				DS[prefix[i]]++;
			}
		}
		cout << res << "\n";
		res = 0;
	}
	return 0;
}
