#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, ans;
string s, t;
vector < int > ab, ba;

int main ()
{
	cin >> N;
	cin >> s >> t;
	for ( int i = 0; i < N; i++ )
	{
		if ( s[i] == 'a' && t[i] == 'b' )
			ab.push_back ( i + 1 );
		if ( s[i] == 'b' && t[i] == 'a' )
			ba.push_back ( i + 1 );
	}
	ans = (ab.size() / 2) + (ba.size() / 2);
	
	if ( ab.size() % 2 == ba.size() % 2 )
	{
		cout << ans + 2*(ab.size() % 2) << "\n";
		for ( int i = 0; i + 1 < ab.size(); i += 2 )
			cout << ab[i] << " " << ab[i + 1] << "\n";
		for ( int i = 0; i + 1 < ba.size(); i += 2 )
			cout << ba[i] << " " << ba[i + 1] << "\n";
		
		if ( ab.size() % 2 == 1 )
		{
			cout << ab[ab.size() - 1] << " " << ab[ab.size() - 1] << "\n";
			cout << ab[ab.size() - 1] << " " << ba[ba.size() - 1] << "\n";
		}
	}
	else
		cout << "-1\n";
	return 0;
}
