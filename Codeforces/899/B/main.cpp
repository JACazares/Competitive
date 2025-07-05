#include <iostream>
#define MAXN 25
using namespace std;
typedef long long int lld;
int N, a[MAXN];
int months[84] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
				  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
				  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
				  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
				  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
				  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
				  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main () {
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int month = 0; month < 84-N+1; month++) {
		for(int i = 0; i < N; i++) {
			
			if(a[i] != months[month+i])
				break;
			if(i == N-1) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}
