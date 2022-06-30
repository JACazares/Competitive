/*
ID: josecaz1
PROG: frac1
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>
#define mp make_pair
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;
ifstream fin("frac1.in");
ofstream fout("frac1.out");
int N;
vector<pii> fractions;

int Gcd(int A, int B) {
	if(B == 0)
		return A;
	return Gcd(B, A%B);
}

int Lcm(int A, int B) {
	return (A*B)/Gcd(A, B);
}

bool cmp(pii A, pii B) {
	bool ans;
	if(A.first == B.first)
		ans = A.second > B.second;
	else if(A.second == B.second)
		ans = A.first < B.first;
	else {
		int lcm = Lcm(A.second, B.second);
		ans = A.first*(lcm/A.second) < B.first*(lcm/B.second);
	}
	return ans;
}

int main () {
	fin >> N;
	fractions.push_back(mp(0, 1));
	fractions.push_back(mp(1, 1));
	for(int i=2; i<=N; i++)
		for(int j=1; j<i; j++)
			if(Gcd(i, j) == 1)
				fractions.push_back(mp(j, i));
	sort(fractions.begin(), fractions.end(), cmp);
	for(int i=0; i<fractions.size(); i++)
		fout << fractions[i].first << "/" << fractions[i].second << "\n";
	return 0;
}
