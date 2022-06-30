#include <iostream>
using namespace std;
int N, row[8], col[8], R[8], C[8];
bool RVisited[8], cont, Attacking[8][8], A[8][8][8][8];

void Attack(int r, int c, int x)
{
	Attacking[r][c] = x;
	A[r][c][r][c] = x;
	for(int i=0; i<8; i++)
		if(!Attacking[i][c] || A[r][c][i][c])
		{
			Attacking[i][c] = x;
			A[r][c][i][c] = x;
		}
	for(int i=0; i<8; i++)
		if(!Attacking[r][i] || A[r][c][r][i])
		{
			Attacking[r][i] = x;
			A[r][c][r][i] = x;
		}
	for(int i=r-1, j=c-1; i>=0 && j >= 0; i--, j--)
		if(!Attacking[i][j] || A[r][c][i][j])
		{
			Attacking[i][j] = x;
			A[r][c][i][j] = x;
		}

	for(int i=r+1, j=c-1; i<8 && j >= 0; i++, j--)
		if(!Attacking[i][j] || A[r][c][i][j])
		{
			Attacking[i][j] = x;
			A[r][c][i][j] = x;
		}
	for(int i=r-1, j=c+1; i>=0 && j<8; i--, j++)
		if(!Attacking[i][j] || A[r][c][i][j])
		{
			Attacking[i][j] = x;
			A[r][c][i][j] = x;
		}
	for(int i=r+1, j=c+1; i<8 && j<8; i++, j++)
		if(!Attacking[i][j] || A[r][c][i][j])
		{
			Attacking[i][j] = x;
			A[r][c][i][j] = x;
		}
}

void Solve(int QLeft, int Row, int Col)
{
	if(QLeft == 0)
	{
		cont = 0;
		return;
	}
	if(RVisited[Row])
		Solve(QLeft, Row+1, 0);
	for(int i=0; i<8; i++)
	{
		if(!Attacking[Row][i])
		{
			Attack(Row, i, 1);
			Solve(QLeft-1, Row+1, i);
			if(!cont)
			{
				if(!RVisited[Row])
					cout << Row+1 << " " << i+1 << "\n";
				return;
			}
			Attack(Row, i, 0);
		}
	}
}

int main ()
{
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> row[i] >> col[i];
	for(int i=0; i<N; i++)
	{
		RVisited[row[i]-1] = 1;
		Attack(row[i]-1, col[i]-1, 1);
	}
	cont = 1;
	Solve(8-N, 0, 0);
	if(cont)
		cout << "0\n";
	else
		for(int i=0; i<N; i++)
			cout << row[i] << " " << col[i] << "\n";
	return 0;
}
