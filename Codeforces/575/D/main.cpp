#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    cout << "2000" << endl;
    for(int i = 1; i <= 1000; i++)
    {
        cout << i << " 1 " << i << " 2" << endl;
    }
    for(int i = 1000; i > 1; i--)
    {
        cout << i << " 1 " << i << " 2" << endl;
    }
    cout << "1 1 1 2";
    return 0;
}
