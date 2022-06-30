/*
ID: josecaz1
PROG: castle
LANG: C++11
*/
#include <iostream>
#include <utility>
#include <fstream>
#define row first
#define col second.first
#define dir second.second
using namespace std;
typedef long long int lld;
ifstream fin("castle.in");
ofstream fout("castle.out");
int N, M, castle[51][51], colored[51][51], sizeroom[2501], nrooms, maxsize, maxwall;
pair<int, pair<int, char> > Remove;

void Input() {
	fin >> M >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			fin >> castle[i][j];
}

bool Up(int r, int c) { if(castle[r][c]&(1<<1))  {return 0;}	return 1;}
bool Down(int r, int c) { if(castle[r][c]&(1<<3)) {return 0;}	return 1;}
bool Left(int r, int c) { if(castle[r][c]&(1<<0)) {return 0;}	return 1;}
bool Right(int r, int c) { if(castle[r][c]&(1<<2)) {return 0;}	return 1;}

bool valid(int r, int c) {
	if(r<0 || r>=N)
		return false;
	if(c<0 || c>=M)
		return false;
	if(colored[r][c])
		return false;
	return true;
}

void color(int r, int c, int x) {
	if(!valid(r, c))
		return;
	colored[r][c] = x;
	sizeroom[x]++;
	if(Up(r, c))	color(r-1, c, x);
	if(Down(r, c))	color(r+1, c, x);
	if(Left(r, c))	color(r, c-1, x);
	if(Right(r, c))	color(r, c+1, x);
}

void floodfill() {
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(!colored[i][j])
				color(i, j, ++nrooms);
}

void wall() {
	for(int j=0; j<M; j++) {
		for(int i=N-1; i>=0; i--) {
			//NorthWall
			if(i>0 && colored[i][j] != colored[i-1][j] && !Up(i, j)) {
				if(maxwall < sizeroom[colored[i][j]]+sizeroom[colored[i-1][j]]) {
					maxwall = sizeroom[colored[i][j]]+sizeroom[colored[i-1][j]];
					Remove.row = i, Remove.col = j, Remove.dir='N';
				}
			}
			//EastWall
			if(j<M-1 && colored[i][j] != colored[i][j+1] && !Right(i, j)) {
				if(maxwall < sizeroom[colored[i][j]]+sizeroom[colored[i][j+1]]) {
					maxwall = sizeroom[colored[i][j]]+sizeroom[colored[i][j+1]];
					Remove.row = i, Remove.col = j, Remove.dir='E';
				}
			}
		}
	}
}
	
int main () {
	Input();
	floodfill();
	for(int i=1; i<=nrooms; i++)
		maxsize = max(maxsize, sizeroom[i]);
	wall();
	fout << nrooms << "\n";
	fout << maxsize << "\n";
	fout << maxwall << "\n";
	fout << Remove.row+1 << " " << Remove.col+1 << " " << Remove.dir << "\n";
	return 0;
}
