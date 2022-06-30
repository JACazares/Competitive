/*
ID: josecaz1
PROG: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lld;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
int numCows, vitamin[25], numFeeds, feed[15][25], value[(1<<15)][25], ans;

void precalculateMask() {
	for(int i=0; i<(1<<numFeeds); i++)
		for(int j=0; j<numFeeds; j++)
			if(i&(1<<j))
				for(int k=0; k<numCows; k++)
					value[i][k]+= feed[j][k];
}

int calc(int a) {
	int ret=0;
	for(int i=0; i<numFeeds; i++)
		ret+= (a&(1<<i))!=0;
	return ret;
}

bool calc2(int a, int b) {
	for(int i=0; i<numFeeds; i++) {
		if((a&(1<<i))==1 && (b&(1<<i))==0)
			return true;
		if((a&(1<<i))==0 && (b&(1<<i))==1)
			return false;
	}
}

int main () {
	fin >> numCows;
	for(int i=0; i<numCows; i++)
		fin >> vitamin[i];
	fin >> numFeeds;
	for(int i=0; i<numFeeds; i++)
		for(int j=0; j<numCows; j++)
			fin >> feed[i][j];
	precalculateMask();
	for(int i=0; i<(1<<numFeeds); i++) {
		int aux=0;
		for(int j=0; j<numCows; j++)
			if(value[i][j] >= vitamin[j])
				aux++;
		if(aux == numCows && (ans == 0 || (calc(i) < calc(ans) || (calc(i) == calc(ans) && calc2(i, ans)))))
			ans = i;
	}
	fout << calc(ans);
	for(int i=0; i<numFeeds; i++)
		if(ans&(1<<i))
			fout << " " << i+1;
	fout << "\n";
	return 0;
}
