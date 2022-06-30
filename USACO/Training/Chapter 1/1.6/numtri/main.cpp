/*
ID: josecaz1
PROG: numtri
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lld;
int DP[1002][1002], Tri[1002][1002], Vis[1002][1002], N, ans;

int Solve(int r, int c)
{
	if(r > N)
		return 0;
	if(Vis[r][c])
		return DP[r][c];
	Vis[r][c] = 1;
	return DP[r][c] = max(Solve(r+1, c), Solve(r+1, c+1))+Tri[r][c];
}

//Basic Functions
void Input() {
	ifstream fin ("numtri.in");
	fin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=i; j++)
			fin >> Tri[i][j];
	fin.close();
}

int main ()
{
	Input();
	ans = Solve(1, 1);
	ofstream fout("numtri.out");
	fout << ans << "\n";
	fout.close();
	return 0;
}
