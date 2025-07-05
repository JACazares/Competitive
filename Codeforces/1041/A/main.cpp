#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> a;

int main()
{
	cin >> N;
	a.resize(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	return 0;
}

