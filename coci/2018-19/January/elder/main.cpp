#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int N, ans;
char wizard, win, lose;
map < char, int > taken;

int main ()
{
	cin >> wizard;
	taken[wizard] = 1;
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		cin >> win >> lose;
		if ( lose == wizard )
		{
			wizard = win;
			taken[wizard] = 1;
		}
	}
	for ( auto i : taken )
		ans += i.second;
	cout << wizard << "\n" << ans << "\n";
	return 0;
}
