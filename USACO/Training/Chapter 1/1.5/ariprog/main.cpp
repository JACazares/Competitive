/*
ID: josecaz1
PROG: ariprog
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#define mp make_pair
using namespace std;
struct solution {
	int f, s;
};
int N, M, Bisquare[125001], n_ans;
pair< int, int > Ans[10001];

void GenerateSquares(int m)
{
	for(int i=0; i<=m; i++)
		for(int j=0; j<=m; j++)
			Bisquare[(i*i)+(j*j)] = 1;
	
}

bool IsProg(int i, int d)
{
	for(int k=1; k<N; k++)
		if(i+(d*k) > 125000 || !Bisquare[i+(d*k)])
			return false;
	return true;
}

//Basic Functions
void Input() {
	ifstream fin("dict.txt");
	for ( int i = 0; i < 4617; i++ )
		fin >> word[i];
	fin.close();

	ifstream fin("namenum.in");
	fin >> N >> M;
	fin.close();
}

int main ()
{
	Input();
	GenerateSquares(M);
	for(int i=0; i<125001; i++)
		if(Bisquare[i])
			for(int j=1; j<=5000; j++)
				if(IsProg(i, j))
					Ans[n_ans++] = mp(j, i);
	ofstream fout("ariprog.out");
	if(n_ans == 0)
		fout << "NONE\n";
	else
	{
		sort(Ans, Ans+n_ans);
		for(int i=0; i<n_ans-1; i++)
			fout << Ans[i].second << " " << Ans[i].first << "\n";
		fout << Ans[n_ans-1].second << " " << Ans[n_ans-1].first << "\n";
	}
	fout.close();
	return 0;
}
