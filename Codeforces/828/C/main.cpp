#include <iostream>
using namespace std;
typedef long long int lld;
int N, k, pos, lastpos;
string s;
char stri[1000000];

int main () {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> s;
		cin >> k;
		for(int j=0; j<k; j++) {
			cin >> pos;
			lastpos = max(lastpos, int(s.length()+pos));
			for(int x=0; x<s.length(); x++)
				stri[x+pos] = s[x];
		}
	}
	for(int i=1; i<lastpos; i++) {
		if(stri[i])
			cout << stri[i];
		else
			cout << "a";
	}
	return 0;
}
