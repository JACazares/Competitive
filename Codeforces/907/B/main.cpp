#include <iostream>
using namespace std;
typedef long long int lld;
int x, y, startX, endX, startY, endY, X, Y;
bool flag = 0;
char board[15][15];

int main () {
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			cin >> board[i][j];
	cin >> x >> y;
	X = (x-1)%3;
	Y = (y-1)%3;
	if(X == 0 && Y == 0) {
		startX = 1;
		endX = 3;
		startY = 1;
		endY = 3;
	}
	if(X == 0 && Y == 1) {
		startX = 1;
		endX = 3;
		startY = 4;
		endY = 6;
	}
	if(X == 0 && Y == 2) {
		startX = 1;
		endX = 3;
		startY = 7;
		endY = 9;
	}
	if(X == 1 && Y == 0) {
		startX = 4;
		endX = 6;
		startY = 1;
		endY = 3;
	}
	if(X == 1 && Y == 1) {
		startX = 4;
		endX = 6;
		startY = 4;
		endY = 6;
		
	}
	if(X == 1 && Y == 2) {
		startX = 4;
		endX = 6;
		startY = 7;
		endY = 9;
		
	}
	if(X == 2 && Y == 0) {
		startX = 7;
		endX = 9;
		startY = 1;
		endY = 3;
		
	}
	if(X == 2 && Y == 1) {
		startX = 7;
		endX = 9;
		startY = 4;
		endY = 6;
		
	}
	if(X == 2 && Y == 2) {
		startX = 7;
		endX = 9;
		startY = 7;
		endY = 9;
		
	}
	for(int i = startX; i <= endX; i++) {
		for(int j = startY; j <= endY; j++) {
			if(board[i][j] == '.') {
				board[i][j] = '!';
				flag = 1;
			}
		}
	}
	if(!flag)
		for(int i = 1; i <= 9; i++)
			for(int j = 1; j <= 9; j++)
				if(board[i][j] == '.')
					board[i][j] = '!';
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			cout << board[i][j];
			if(j % 3 == 0)
				cout << " ";
		}
		cout << "\n";
		if(i % 3 == 0)
			cout << "\n";
	}
	return 0;
}
