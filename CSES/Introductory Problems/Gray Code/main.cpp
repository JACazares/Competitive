#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    for(int i = 0; i < (1 << N); i++)
    {
        for(int j = N; j >= 1; j--)
        {
            int group = i / (1 << j);
            int pos = i % (1 << j);

            if(group % 2 == 0)
            {
                if(pos < (1 << (j - 1)))
                    cout << "0";
                else
                    cout << "1";
            }  
            else
            {
                if(pos < (1 << (j - 1)))
                    cout << "1";
                else
                    cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}