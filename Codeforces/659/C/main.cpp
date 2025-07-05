#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef long long int lld;
int N, maxim, a[MAXN], tot, cnt = 1, aux;
vector<int> answer;

int main() {
	cin >> N >> maxim;
	for(int i = 0; i < N; i++)
		cin >> a[i];
    sort(a, a+N);
	while(tot <= maxim) {
		if(aux == N || cnt < a[aux]) {
			tot+= cnt;
			answer.push_back(cnt);
		} else if(cnt >= a[aux])
			aux++;
		cnt++;
	}
	cout << answer.size() - 1 << "\n";
	for(int i = 0; i < answer.size() - 1; i++)
		cout << answer[i] << " ";
	cout << "\n";
	return 0;
}
