/*
ID: josecaz1
PROG: hamming
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef long long int lld;
ifstream fin("hamming.in");
ofstream fout("hamming.out");
int N, B, D, cnt;
vector<int> codewords;

int hammingDistance(int a, int b) {
	int retVal = 0;
	for(int i=0; i<B; i++) {
		if((a&(1<<i)) != (b&(1<<i)))
			retVal++;
	}
	return retVal;
}

int main () {
	fin >> N >> B >> D;
	for(int i=0; i<(1<<B); i++) {
		if(codewords.size() == N)
			break;
		if(i == 0)
			codewords.push_back(i);
		else {
			cnt = 0;
			for(int j=0; j<codewords.size(); j++)
				if(hammingDistance(i, codewords[j]) >= D)
					cnt++;
			if(cnt == codewords.size())
				codewords.push_back(i);
		}
	}
	for(int i=0; i<codewords.size(); i++)
		fout << codewords[i] << ((i%10 == 9 && i != 0) || i == codewords.size()-1 ? "\n" : " ");
	return 0;
}
