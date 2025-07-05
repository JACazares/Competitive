#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    bitset<64000001> mem;
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int a[N];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        for(int i = 0; i < N; i++)
        {
            int sum = a[i];
            for(int j = i + 1; j < N; j++)
            {
                sum += a[j];
                mem.set(sum);
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++)
            if(mem.test(a[i]))
                ans++;
        mem.reset();
        cout << ans << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT

