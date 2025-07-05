#include <iostream>
using namespace std;
typedef long long int lld;
int N, x, y;
char a;

int main () {
	cin >> N;
	for(int i = 0 ; i < N ; i++) {
		cin >> a;
		if(a == 'U')
			x++;
		if(a ==  'D')
			x--;
		if(a == 'L')
			y++;
		if(a == 'R')
			y--;
	}
	cout << N - abs(x) - abs(y);
	return 0;
}
