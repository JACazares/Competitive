#include <iostream>

using namespace std;

int main()
{
    int P, H, O;
    while(cin >> P >> H >> O)
    {
        cout << (H <= O - P ? "Props win!" : "Hunters win!") << "\n";
    }
    return 0;
}