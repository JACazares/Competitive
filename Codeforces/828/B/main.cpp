#include <iostream>
#include <utility>
#define mp make_pair
#define pii pair<int, int>
using namespace std;
typedef long long int lld;
int N, M, ll, sl;
char Board[100][100];
pii tl, tr, dr, dl;

pii TopLeft() {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(Board[i][j] == 'B')
				return mp(i, j);
	return mp(0, 0);
}

pii TopRight() {
	for(int i=0; i<N; i++)
		for(int j=M-1; j>=0; j--)
			if(Board[i][j] == 'B')
				return mp(i, j);
	return mp(0, 0);
}

pii DownRight() {
	for(int i=N-1; i>=0; i--)
		for(int j=M-1; j>=0; j--)
			if(Board[i][j] == 'B')
				return mp(i, j);
	return mp(0, 0);
}

pii DownLeft() {
	for(int i=N-1; i>=0; i--)
		for(int j=0; j<M; j++)
			if(Board[i][j] == 'B')
				return mp(i, j);
	return mp(0, 0);
}

int GetSum(pii a, pii b) {
	int ret=0;
	for(int i=a.first; i<= b.first; i++)
		for(int j=a.second; j<= b.second; j++)
			if(Board[i][j] == 'W')
				ret++;
	return ret;
}

int main () {
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> Board[i][j];
	tl = TopLeft();
	tr = TopRight();
	dl = DownLeft();
	dr = DownRight();
	tl = mp(tl.first, min(dl.second, tl.second));
	tr = mp(tr.first, max(dr.second, tr.second));
	dl = mp(dl.first, min(tl.second, dl.second));
	dr = mp(dr.first, max(tr.second, dr.second));
	ll = tr.second-tl.second;
	sl = dl.first-tl.first;
	if(ll > sl) {
		pii tl2 = mp(dl.first-ll, tl.second);
		pii dr2 = dr;
		int ans = 9999999;
		while(tl2.first <= tl.first && dr2.first < M) {
			while(tl2.first < 0)
				tl2.first++, dr2.first++;
			if(dr2.first >= N)
				ans = -1;
			ans = min(ans, GetSum(tl2, dr2));
			tl2.first++, dr2.first++;;
		}
		cout << ans << "\n";
	} else if(sl > ll) {
		pii tl2 = mp(tl.first, tr.second-sl);
		pii dr2 = dr;
		int ans = 9999999;
		while(tl2.second <= tl.second && dr2.second < M) {
			while(tl2.second < 0)
				tl2.second++, dr2.second++;
			if(dr2.second >= M)
				ans = -1;
			ans = min(ans, GetSum(tl2, dr2));
			tl2.second++, dr2.second++;;
		}
		cout << ans << "\n";
	} else {
		cout << GetSum(tl, dr) << "\n";
	}
	return 0;
}
