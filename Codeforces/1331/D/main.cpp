#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    string N;
	cin >> N;
    cout << ((int(N[N.length() - 1] - '0')) & 1) << "\n";
	return 0;
}
