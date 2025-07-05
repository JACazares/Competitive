#include <iostream>
#include <algorithm>
using namespace std;
int N, K;

long long int choose(int a, int b) {
	long long int res=1;
	for(int i=a; i>a-b; i--)
		res*= i;
	for(int i=b; i>=1; i--)
		res/= i;
	return res;
}

int main() {
	cin >> N >> K;
	if(K == 1)
		cout << "1\n";
	if(K == 2)
		cout << choose(N, 2)+1 << "\n";
	if(K == 3)
		cout << 2*choose(N, 3)+choose(N, 2)+1 << "\n";
	if(K == 4)
		cout << 9*choose(N, 4)+2*choose(N, 3)+choose(N, 2)+1 << "\n";
	return 0;
}
