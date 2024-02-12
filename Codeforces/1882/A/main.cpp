#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int N, a, curr = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		curr++;
		cin >> a;
		if(curr == a)
			curr++;
	}
	
	cout << curr << "\n";
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
