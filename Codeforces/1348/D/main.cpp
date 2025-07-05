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
        int m = 1, b = 1, s, e, mid, minim;
        vi ans;
        while(m != N)
        {
            if(m + 2*b >= N)
            {
                ans.push_back(N - m - b);
                break;
            }
            int init = b;
            s = b, e = 2*b;
            while(s <= e)
            {
                mid = (s + e) / 2; //b
                minim = m + 2*mid;
                
                if(minim <= N)
                {
                    b = mid;
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
            ans.push_back(b - init);
            m += b;
        }
        cout << ans.size() << "\n";
        for(auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
