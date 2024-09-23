#include <iostream>

using namespace std;

int main()
{
    int R, N, t = 0;
    while(cin >> R >> N)
    {
        if(R == 0 && N == 0)
            break;

        cout << "Case " << ++t << ": ";
        if((R + N - 1) / N > 27)
            cout << "impossible\n";
        else
            cout << ((R + N - 1) / N) - 1 << "\n";
    }
    return 0;
}