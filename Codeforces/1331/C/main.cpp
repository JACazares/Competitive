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
	//And after happily lived ever they
    //And they lived happily ever after
    int tmp, tmp2;
    tmp = (N & (1 << 4));
    tmp2 = (N & (1 << 0));
    if(tmp)
        N |= (1 << 0);
    else
        N &= (~(1 << 0));

    if(tmp2)
        N |= (1 << 4);
    else
        N &= (~(1 << 4));

    tmp = (N & (1 << 3));
    tmp2 = (N & (1 << 2));
    if(tmp)
        N |= (1 << 2);
    else
        N &= (~(1 << 2));

    if(tmp2)
        N |= (1 << 3);
    else
        N &= (~(1 << 3));
    cout << N << "\n";
	return 0;
}
