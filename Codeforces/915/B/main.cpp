#include <iostream>
using namespace std;
typedef long long int lld;
int N, pos, l, r, mid, delta;

int main () {
	cin >> N >> pos >> l >> r;
	mid = (l + r) / 2;
	if(pos < l) {
		delta = l - pos;
		pos = l;
	}
	if(pos > r) {
		delta = pos - r;
		pos = r;
	}
	if(pos <= mid) {
		if(l > 1 && r < N)
			cout << (pos - l) + (r - l) + 2 + delta << "\n";
		
	} else {
		if(l > 1 && r < N)
			cout << (r - pos) + (r - l) + 2 + delta<< "\n";
	}
	if(l == 1 && r < N)
		cout << (r - pos) + 1 + delta<< "\n";
	if(l > 1 && r == N)
		cout << (pos - l) + 1 + delta<< "\n";
	if(l == 1 && r == N)
		cout << "0" << "\n";
	return 0;
}
