#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, a;
stack < int > S;

int main ()
{
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		cin >> a, a %= 2;

		if ( S.empty() or S.top() != a )
			S.push ( a );
		else
			S.pop();
	}
	
	if ( S.size() <= 1 )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
