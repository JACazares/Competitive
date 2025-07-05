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
        int a[N], diff = 0;
        vi vis(N + 5, 0);
        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
            if(!vis[a[i]])
                diff++;
            vis[a[i]]++;
        }
        int maxEq = 0;
        for(int i = 0; i < N; i++)
            maxEq = max(maxEq, vis[a[i]]);

        //team 1 can have diff students, team2 can have maxEq - 1
        //team 1 can have diff - 1 students, team2 can have maxEq

        if(diff <= maxEq - 1)
            cout << diff << "\n";
        else if(diff - 1 >= maxEq)
            cout << maxEq << "\n";
        else
            cout << diff - 1 << "\n";
    }
    return 0;
}
