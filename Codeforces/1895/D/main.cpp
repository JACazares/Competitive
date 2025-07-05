#include <bits/stdc++.h>

const int MAXN = 2e5+10;

using namespace std;

int save[MAXN];
int n;

// int calc(int x) {
// 	return 31-x.__builtin_clz();
// }

bool is_on(int x, int i) {
	return (x&(1<<i)) != 0;
}

void faz(int resp){
	cout << resp << " ";
	for(int i = 0; i < n-1; i++){
		cout << (resp^save[i]) << " ";
	}
	cout << endl;
	exit(0);
}

void rec(vector<int> a, int num, int cur, int cur_num) {
	
	if(cur == -1 || a.size() == 0){

		if(a.size() == 0){
			cur_num <<= (cur+1); ;
			if(cur_num < n)
				faz(cur_num); 
		}
		return;
	}
	vector<int> g[2];
	for(auto e : a){
		if(e > 0) {
			g[is_on(e,cur)].push_back(e);	
		}
	}

	if(is_on(num, cur)){
		// cout <<g[1].size() << " " << cur_num << " " << "aqui " << endl;
		rec(g[1], num, cur-1, (cur_num<<1));
		rec(g[0], num, cur-1, (cur_num<<1)+1);
	} else {
		if(g[0].size() == 0){
			rec(g[1], num, cur-1, ((cur<<num)<<1)+1);
		} 
		if(g[1].size() == 0){
			rec(g[0], num, cur-1, ((cur<<num)<<1));
		}
	}
}

void solve(){

	cin >> n;
	vector<int> a(n-1);
	for(int i = 0; i < n-1; i++){
		cin >> a[i];
		if(i) a[i] = a[i]^a[i-1];
		save[i] = a[i];
	}
	int pot = 0;
	while((1<<pot) <= n){
		pot++;
	}
	rec(a, n, pot-1, 0);
}

int main() {
	int t;
	// cin >> t;
	t = 1;
	for(int i = 0; i < t; i++){
		solve();
	}
}
