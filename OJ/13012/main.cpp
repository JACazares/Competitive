#include <iostream>

using namespace std;

int main()
{
    int T;
    while(cin >> T)
    {
        int ans = 0;
        for(int i = 0; i < 5; i++)
        {
            int guess;
            cin >> guess;
            if(guess == T)
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}