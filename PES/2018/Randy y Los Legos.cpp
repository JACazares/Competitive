#include <iostream>
#define MAXN 2000
using namespace std;
int N, M, answer[6];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char T[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool valid(int i, int j) {
	if(i < 0 || i >= N)
		return false;
	if(j < 0 || j >= M)
		return false;
	if(visited[i][j])
		return false;
	return true;
}

void floodfill(int i, int j) {
	visited[i][j] = 1;
	for(int k=0; k<4; k++)
		if(valid(i+dx[k], j+dy[k]) && T[i+dx[k]][j+dy[k]] == T[i][j])
			floodfill(i+dx[k], j+dy[k]);
}

bool valid2(int i, int j) {
	if(i < 0 || i >= N)
		return false;
	if(j < 0 || j >= M)
		return false;
	return true;
}

int getShape(int i, int j) {
	char a = T[i][j];
	//Shape 1
	if(valid2(i+1, j+2))
		if(T[i][j] == a && T[i][j+1] == a && T[i][j+2] == a && T[i+1][j+2] == a) return 0;
	if(valid2(i+2, j-1))
		if(T[i][j] == a && T[i+1][j] == a && T[i+2][j] == a && T[i+2][j-1] == a) return 0;
	if(valid2(i+1, j+2))
		if(T[i][j] == a && T[i+1][j] == a && T[i+1][j+1] == a && T[i+1][j+2] == a) return 0;
	if(valid2(i+2, j-1))
		if(T[i][j] == a && T[i][j+1] == a && T[i+1][j] == a && T[i+2][j] == a) return 0;

	//Shape 2
	if(valid2(i+1, j+1) && valid2(i+1, j-2))
		if(T[i][j] == a && T[i+1][j] == a && T[i+1][j+1] == a && T[i+1][j-1] == a && T[i+1][j-2] == a) return 1;
	if(valid2(i+3, j) && valid2(i+2, j+1))
		if(T[i][j] == a && T[i+1][j] == a && T[i+2][j] == a && T[i+2][j+1] == a && T[i+3][j] == a) return 1;
	if(valid2(i, j+3) && valid2(i+1, j+1))
		if(T[i][j] == a && T[i][j+1] == a && T[i+1][j+1] == a && T[i][j+2] == a && T[i][j+3] == a) return 1;
	if(valid2(i+3, j-1))
		if(T[i][j] == a && T[i+1][j] == a && T[i+2][j] == a && T[i+3][j] == a && T[i+1][j-1] == a) return 1;

	//Shape 3
	if(valid2(i+2, j+1) && valid2(i+2, j-1))
		if(T[i][j] == a && T[i+1][j-1] == a && T[i+1][j] == a && T[i+1][j+1] == a && T[i+2][j] == a) return 2;

	//Shape 4
	if(valid2(i+2, j+2))
		if(T[i][j] == a && T[i][j+1] == a && T[i+1][j+1] == a && T[i+1][j+2] == a && T[i+2][j+1] == a) return 3;
	if(valid2(i+2, j-2))
		if(T[i][j] == a && T[i+1][j] == a && T[i+1][j-1] == a && T[i+1][j-2] == a && T[i+2][j-1] == a) return 3;
	if(valid2(i+2, j+1) && valid2(i+2, j-1))
		if(T[i][j] == a && T[i+1][j] == a && T[i+1][j-1] == a && T[i+2][j] == a && T[i+2][j+1] == a) return 3;
	if(valid2(i+2, j+1) && valid2(i+2, j-1))
		if(T[i][j] == a && T[i+1][j] == a && T[i+1][j+1] == a && T[i+1][j-1] == a && T[i+2][j-1] == a) return 3;

	//Shape 5
	if(valid2(i+2, j+2))
		if(T[i][j] == a && T[i][j+1] == a && T[i+1][j+1] == a && T[i+2][j+1] == a && T[i+2][j+2] == a) return 4;
	if(valid2(i+2, j-2))
		if(T[i][j] == a && T[i+1][j] == a && T[i+1][j-1] == a && T[i+1][j-2] == a && T[i+2][j-2] == a) return 4;

	//Shape 6
	if(valid2(i+2, j+2))
		if(T[i][j] == a && T[i][j+1] == a && T[i][j+2] == a && T[i+1][j] == a && T[i+1][j+1] == a && T[i+1][j+2] == a && T[i+2][j] == a && T[i+2][j+1] == a && T[i+2][j+2] == a) return 5;

}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> T[i][j];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(T[i][j] != '.' && !visited[i][j]) {
				floodfill(i, j);
				answer[getShape(i, j)]++;
			}
	for(int i=0; i<6; i++)
		cout << answer[i] << "\n";
	return 0;
}
