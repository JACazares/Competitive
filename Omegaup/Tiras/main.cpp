#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef long long int lld;
struct tira {
	lld start, end;
};
lld N, l, fStart=-1, ans;
tira Tira[MAXN];

bool cmp(tira a, tira b) {
	return a.end < b.end;
}

int main () {
        ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> Tira[i].start >> l;
		Tira[i].end = Tira[i].start+l+1;
	}
	sort(Tira+1, Tira+N+1, cmp);
	for(int i=1; i<=N; i++) {
		if(Tira[i].start >= FStart)
			fStart = Tira[i].end;
		else
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
