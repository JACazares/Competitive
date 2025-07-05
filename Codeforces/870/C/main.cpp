#include <iostream>
using namespace std;
int N, a;

int solve(int n) {
	int res = 0;
	if(n <= 3 || n == 5 || n == 7 || n == 11)
		return -1;
	if(n%2 == 1)
		n-=9, res++;
	if(n%4 == 2)
		n-=6, res++;
	res+= n/4;
	return res;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a;
		cout << solve(a) << "\n";
	}
	return 0;
}
