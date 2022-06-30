/*
ID: josecaz1
PROG: sort3
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lld;
ifstream fin("sort3.in");
ofstream fout("sort3.out");
int N, Seq[1000], ans=0, num[4], bucket[4][4];
//bucket[What Should Be Here][What's Actually Here]

void createBuckets() {
	for(int i=0; i<N; i++)
		num[Seq[i]]++;
	num[3] = num[1]+num[2];
	num[2] = num[1];
	num[1] = 0;
	num[0] = 0;
	int place = 0;
	for(int i=0; i<N; i++) {
		while(i == num[place+1])
			place++;
		bucket[place][Seq[i]]++;
	}
}

int min3(int a, int b, int c) {
	return min(a, min(b, c));
}

int calculateDirectMoves() {
	int retResult = 0;
	retResult+= min(bucket[1][2], bucket[2][1]);
		if(bucket[1][2] < bucket[2][1])	bucket[2][1]-= bucket[1][2], bucket[1][2] = 0;
		else	bucket[1][2]-= bucket[2][1], bucket[2][1] = 0;
	retResult+= min(bucket[1][3], bucket[3][1]);
		if(bucket[1][3] < bucket[3][1])	bucket[3][1]-= bucket[1][3], bucket[1][3] = 0;
		else	bucket[1][3]-= bucket[3][1], bucket[3][1] = 0;
	retResult+= min(bucket[2][3], bucket[3][2]);
		if(bucket[2][3] < bucket[3][2])	bucket[3][2]-= bucket[2][3], bucket[2][3] = 0;
		else	bucket[2][3]-= bucket[3][2], bucket[3][2] = 0;
	return retResult;
}

int calculateIndirectMoves() {
	int retResult = 0;
	retResult+= min3(bucket[1][2], bucket[2][3], bucket[3][1]);
	retResult+= min3(bucket[2][1], bucket[3][2], bucket[1][3]);
	return retResult*2;
}

int main () {
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> Seq[i];
	/** There are 2 main types of movement:
			Direct Move: Where a B is in the A place and an A is in the B place
						 Where a C "       " A "          " A "       " C "   "
						 Where a C "       " B "          " B "       " C "   "
		  Indirect Move: Where an A is on the B place, a B is on the C place and a C is on the A place
		  				 "      " A "       " C "      " B "       " A "         " C "       " B "   "
		 - Direct Move: Only one exchange is required
		 - Indirect Move: Two exchanges are required
	*/
	createBuckets();
	ans+= calculateDirectMoves();
	ans+= calculateIndirectMoves();
	fout << ans << "\n";
	return 0;
}
