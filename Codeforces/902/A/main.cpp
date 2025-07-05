#include <iostream>
#include <vector>
using namespace std;
typedef long long int lld;
int N, location, start, len;
vector<bool> house;

int main () {
	house.resize(205);
	cin >> N >> location;
	for(int i = 0; i < N; i++) {
		cin >> start >> len;
		if(start == 0 || house[start] == 1)
			for(int j = start; j <= len; j++)
				house[j] = 1;
	}
	if(house[location])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
