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
    int k, pwr2 = (1 << 18) - 1;
	cin >> k;
	cout << "3 4\n";
    cout << pwr2 << " " << k << " " << k << " 0\n";
    cout << (1 << 17) << " 0 " << k << " 0\n";
    cout << pwr2 << " " << pwr2 << " " << pwr2 << " " << k << "\n";
	return 0;
}
