/*
ID: josecaz1
PROG: milk3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
int MaxA, MaxB, MaxC;
bool Visited[21][21][21], Answer[21];

void Solve(int a, int b, int c)
{
	if(a+b+c != MaxC)
		return;
	if(Visited[a][b][c])
		return;
	else
		Visited[a][b][c] = 1;
	if(a == 0)
		Answer[c] = 1;
	if(a > 0)
	{
		//Pour from A to B
		if(a+b <= MaxB)
			Solve(0, b+a, c);
		else
			Solve(a-(MaxB-b), MaxB, c);
		//Pour from A to C
		if(a+c <= MaxC)
			Solve(0, b, c+a);
		else
			Solve(a-(MaxC-b), b, MaxC);
	}
	if(b > 0)
	{
		//Pour from B to A
		if(b+a <= MaxA)
			Solve(a+b, 0, c);
		else
			Solve(MaxA, b-(MaxA-a), c);
		//Pour from B to C
		if(b+c <= MaxC)
			Solve(a, 0, c+b);
		else
			Solve(a, b-(MaxC-c), MaxC);
	}
	if(c > 0)
	{
		//Pour from C to A
		if(c+a <= MaxA)
			Solve(a+c, b, 0);
		else
			Solve(MaxA, 0, c-(MaxA-a));
		//Pour from C to B
		if(c+b <= MaxB)
			Solve(a, b+c, 0);
		else
			Solve(a, MaxB, c-(MaxB-b));
	}
}

int main()
{
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	cin >> MaxA >> MaxB >> MaxC;
	Solve(0, 0, MaxC);
	int i;
	for(i = 0; i<21; i++)
		if(Answer[i])
		{
			cout << i;
			break;
		}
	for(i = i+1; i<21; i++)
		if(Answer[i])
			cout << " " << i;
	cout << "\n";
	return 0;
}
