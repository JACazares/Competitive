#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)2e5 + 5;
int N;
long long a[MAXN];

void solve()
{
	long long sum = 0;
	int firstpos = 0;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		if(a[i] >= 0)
		{
			sum += a[i];
			if(!firstpos)
				firstpos = i;
		}
	}
	
	if(firstpos == 0)
		cout << "0\n";
	else
	{
		if(firstpos % 2 == 1)
			cout << sum << "\n";
		else
		{
			if(firstpos == 2)
				cout << max(sum + a[firstpos - 1], sum - a[firstpos]) << "\n";
			else
				cout << sum << "\n";
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
