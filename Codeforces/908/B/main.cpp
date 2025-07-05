#include <iostream>
#include <map>
#define MAXN 55
using namespace std;
typedef long long int lld;
int N, M, StartPosX, StartPosY, ans, cmd;
bool used[4];
char world[MAXN][MAXN];
string commands;
map<char, int> Dir;

bool valid(int row, int col) {
	if(row < 0 || row >= N)
		return false;
	if(col < 0 || col >= M)
		return false;
	if(world[row][col] == '#')
		return false;
	return true;
}

bool solve(int row, int col, int index) {
	if(!valid(row, col))
		return false;
	//cout << " " << row << " " << col << " " << index << "\n";
	if(world[row][col] == 'E')
		return true;
	if(index == commands.length())
		return false;
	if(Dir[commands[index]] == 0) {
		return solve(row-1, col, index+1);
	} else if(Dir[commands[index]] == 1) {
		return solve(row+1, col, index+1);
	} else if(Dir[commands[index]] == 2) {
		return solve(row, col+1, index+1);
	} else {
		return solve(row, col-1, index+1);
	}
}

int main () {
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) {
			cin >> world[i][j];
			if(world[i][j] == 'S')
				StartPosX = i, StartPosY = j;
		}
	cin >> commands;
	for(int dir0 = 0; dir0 < 4; dir0++) {
		for(int dir1 = 0; dir1 < 4; dir1++) {
			if(dir0 == dir1)
				continue;
			for(int dir2 = 0; dir2 < 4; dir2++) {
				if(dir0 == dir2 || dir1 == dir2)
					continue;
				for(int dir3 = 0; dir3 < 4; dir3++) {
					if(dir0 == dir3 || dir1 == dir3 || dir2 == dir3)
						continue;
					Dir['0'] = dir0;
					Dir['1'] = dir1;
					Dir['2'] = dir2;
					Dir['3'] = dir3;
					//cout << dir0 << " " << dir1 << " " << dir2 << " " << dir3 << "\n";
					if(solve(StartPosX, StartPosY, 0)) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
