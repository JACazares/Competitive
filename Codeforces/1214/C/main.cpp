#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, cnt, minim;
string S;

int main ()
{
	cin >> N;
	cin >> S;
	
	for ( auto i : S )
	{
		if ( i == ')' )
			cnt--;
		else
			cnt++;
		
		minim = min ( minim, cnt );
	}
	if ( minim >= -1 && cnt == 0 )
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
