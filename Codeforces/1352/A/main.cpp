#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int pw = 1;
        vi ans;
        while(N)
        {
            if(N%10 != 0)
                ans.push_back(N%10*pw);
            pw *= 10;
            N /= 10;
        }
        cout << ans.size() << "\n";
        for(auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
