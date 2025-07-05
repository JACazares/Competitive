#include <iostream>
using namespace std;
typedef long long int lld;
int N, Count;
char s;

int main () {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> s;
		if(s == '1')
			Count++;
		if(s == '0' || i == N-1) {
			cout << Count;
			Count=0;
		}
	}
	if(s == '0')
		cout << "0";
	cout << "\n";
	return 0;
}
