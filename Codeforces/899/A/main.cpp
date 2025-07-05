#include <iostream>
using namespace std;
typedef long long int lld;
int N, a, bucket[5];

int main () {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a;
		bucket[a]++;
	}
	cout << min(bucket[1], bucket[2])+((bucket[1]-min(bucket[1], bucket[2]))/3);
	return 0;
}
