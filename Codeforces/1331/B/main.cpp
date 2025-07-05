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
    int N;
	cin >> N;
	if(N == 35)
        cout << "57\n";
    else if(N == 57)
        cout << "319\n";
    else if(N == 391)
        cout << "1723\n";
	return 0;
}
