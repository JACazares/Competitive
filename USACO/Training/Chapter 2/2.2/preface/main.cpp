/*
ID: josecaz1
PROG: preface
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <utility>
#define mp make_pair
using namespace std;
typedef long long int lld;
ifstream fin("preface.in");
ofstream fout("preface.out");
int N, ans[7];
char Roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
bool flag;
stack<pair<char, int> > Answer;

void convert(int i) {
	int cnt = 0;
	while(i>0) {
		if(i%10 <= 3)
			ans[2*cnt]+= i%10;
		else if(i%10 == 5)
			ans[2*cnt+1]++;
		else if(i%10 == 4 || i%10 == 6)
			ans[2*cnt+1]++, ans[2*cnt]++;
		else if(i%10 <= 8)
			ans[2*cnt+1]++, ans[2*cnt]+= (i%10)-5;
		else
			ans[2*cnt]++, ans[2*cnt+2]++;
		i/=10, cnt++;
	}
}

int main () {
	fin >> N;
	for(int i=1; i<= N; i++)
		convert(i);
	for(int i=6; i>=0; i--) {
		flag = (ans[i] > 0 ? 1 : flag);
		if(flag)
			Answer.push(mp(Roman[i], ans[i]));
	}
	while(!Answer.empty())
		fout << Answer.top().first << " " << Answer.top().second << "\n", Answer.pop();
	return 0;
}
