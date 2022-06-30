#include <iostream>
#include <map>
#define MAXN 35
using namespace std;

struct trie
{
	int child[26];
	bool flag;
} Trie[3200];

int N, M, cnt = 0, ans, DP[35][35][3200];
char tablero[MAXN][MAXN];
string palabra, A[26];
map<string, map<int, int> > MAP[MAXN];

void Insert(string word, int ind)
{
	int let;
	for ( int i = 0; i < word.length(); i++ )
	{
		let = word[i] - 'A';
		if ( !Trie[ind].child[let] )
			Trie[ind].child[let] = ++cnt;
		ind = Trie[ind].child[let];
	}

	Trie[ind].flag = 1;
}

bool partial_look ( char letter, int ind )
{
	int let;
	let = letter - 'A';
	if ( !Trie[ind].child[let] )
		return false;
	
	return true;
}

int search ( int r, int c, int ind )
{
	if ( DP[r][c][ind] > -1 )
		return DP[r][c][ind];

	int retVal = 0;
	for ( int i = r; i >= 0; i-- )
		for ( int j = c; j < M; j++ )
			if ( i != r || j != c )
				if ( partial_look( tablero[i][j], ind ) )
					retVal += search( i, j, Trie[ind].child[tablero[i][j] - 'A']);
	return DP[r][c][ind] = retVal + Trie[ind].flag;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < M; j++ )
			cin >> tablero[i][j];

	//while ( cin >> palabra ) Insert(palabra, 0);
	for ( int i = 0; i < 2265; i++ )
	{
		cin >> palabra;
		Insert( palabra, 0 );
	}

	for ( int i = 0; i < N + 2; i++ )
		for ( int j = 0; j < M + 2; j++ )
			for ( int k = 0; k < 40000; k++ )
				DP[i][j][k] = -1;

	A[0] = "A";
	A[1] = "B";
	A[2] = "C";
	A[3] = "D";
	A[4] = "E";
	A[5] = "F";
	A[6] = "G";
	A[7] = "H";
	A[8] = "I";
	A[9] = "J";
	A[10] = "K";
	A[11] = "L";
	A[12] = "M";
	A[13] = "N";
	A[14] = "O";
	A[15] = "P";
	A[16] = "Q";
	A[17] = "R";
	A[18] = "S";
	A[19] = "T";
	A[20] = "U";
	A[21] = "V";
	A[22] = "W";
	A[23] = "X";
	A[24] = "Y";
	A[25] = "Z";

	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < M; j++ )
			if ( partial_look ( tablero[i][j], 0 ) )
				ans += search(i, j, Trie[0].child[tablero[i][j] - 'A']);

	cout << ans << "\n";
	
	return 0;
}
