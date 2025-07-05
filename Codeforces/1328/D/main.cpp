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
        int a[N], pairs = 0;
        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
            if(i > 0 && a[i] == a[i - 1])
                pairs++;
        }
        if(a[0] == a[N - 1])
            pairs++;
        if(pairs == N)
        {
            cout << "1\n";
            for(int i = 0; i < N; i++)
                cout << "1 ";
            cout << "\n";
        }
        else if(N % 2 == 0)
        {
            cout << "2\n";
            for(int i = 0; i < N; i++)
                cout << i%2 + 1 << " ";
            cout << "\n";
        }
        else if(N % 2 == 1)
        {
            if(pairs)
            {
                cout << "2\n";
                if(a[0] == a[N - 1])
                {
                    for(int i = 0; i < N; i++)
                        cout << i%2 + 1 << " ";
                    cout << "\n";
                }
                else
                {
                    int cnt = 0;
                    for(int i = 0; i < N; i++)
                    {
                        if(i > 0 && a[i - 1] == a[i] && pairs)
                        {
                            cnt = 1;
                            pairs = 0;
                        }
                        cout << (i+cnt)%2 + 1 << " ";
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "3\n";
                for(int i = 0; i < N - 1; i++)
                    cout << i%2 + 1 << " ";
                cout << "3\n";
            }
        }
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
