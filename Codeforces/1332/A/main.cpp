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
    int T;
	cin >> T;
	while(T--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int r, u;
        r = b - a;
        u = d - c;
        int ans = 0;
        if(x1 <= x + r && x + r <= x2)
            if(y1 <= y + u && y + u <= y2)
                ans = 1;
        if(max(b, a) >= 1 && !(x + 1 <= x2 || x - 1 >= x1))
            ans = 0;
        if(max(d, c) >= 1 && !(y + 1 <= y2 || y - 1 >= y1))
            ans = 0;
        cout << (ans ? "Yes" : "No") << "\n";
    }
	return 0;
}
