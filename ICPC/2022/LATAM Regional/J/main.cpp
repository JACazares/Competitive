#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXL = 30;
int N;
vi first_let(MAXL, 0);
vector<vi> word;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		first_let[s[0] - 'A']++;
		
		vi _freq(MAXL, 0);
		for(auto j : s)
			_freq[j - 'A']++;
		word.pb(_freq);
	}
	
	for(int i = 0; i < N; i++)
	{
		int cnt = 0;
		for(int j = 0; j < MAXL; j++)
			if((word[i][j] > 0 && first_let[j] > 0) || word[i][j] == 0)
				cnt++;
		
		if(cnt == MAXL)
		{
			cout << "Y\n";
			return 0;
		}
	}
	
	cout << "N\n";
	return 0;
}
