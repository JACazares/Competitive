#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll area = 0;
vector<pair<int, int>> dim;

int main()
{
    dim.resize(3);
    for(int i = 0; i < 3; i++)
    {
        cin >> dim[i].first >> dim[i].second;
        area += dim[i].first * dim[i].second;
    }

    int lado = sqrt(area);
    if(lado * lado != area)
    {
        cout << "-1\n";
        return 0;
    }
    
    int permutaciones[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

    for(int perm = 0; perm < 6; perm++)
    {
        // A -> permutaciones[perm][0]
        // B -> permutaciones[perm][1]
        // C -> permutaciones[perm][2]

        for(int flip = 0; flip < (1 << 3); flip++)
        {
            for(int i = 0; i < 3; i++)
                if(flip & (1 << i))
                    swap(dim[i].first, dim[i].second);
        
            // for(int i = 0; i < 3; i++)
            //     cout << dim[i].first << " " << dim[i].second << ", ";
            // cout << "\n";

            // A B C
            int a = permutaciones[perm][0];
            int b = permutaciones[perm][1];
            int c = permutaciones[perm][2];

            if(dim[a].first == dim[b].first && dim[b].first == dim[c].first && dim[a].first == dim[a].second + dim[b].second + dim[c].second)
            {
                cout << lado << "\n";
                for(int i = 0; i < dim[a].first; i++)
                {
                    for(int j = 0; j < dim[a].second; j++)
                        cout << (char)(a + 'A');
                    for(int j = 0; j < dim[b].second; j++)
                        cout << (char)(b + 'A');
                    for(int j = 0; j < dim[c].second; j++)
                        cout << (char)(c + 'A');
                    cout << "\n";
                }

                return 0;
            }

            // AA
            // BC
            if(dim[a].second == dim[b].second + dim[c].second && dim[b].first == dim[c].first)
            {
                cout << lado << "\n";
                for(int i = 0; i < dim[a].first; i++)
                {
                    for(int j = 0; j < dim[a].second; j++)
                        cout << (char)(a + 'A');
                    cout << "\n";
                }
                for(int i = 0; i < dim[b].first; i++)
                {
                    for(int j = 0; j < dim[b].second; j++)
                        cout << (char)(b + 'A');
                    for(int j = 0; j < dim[c].second; j++)
                        cout << (char)(c + 'A');
                    cout << "\n";
                }
                return 0;
            }

            for(int i = 0; i < 3; i++)
                if(flip & (1 << i))
                    swap(dim[i].first, dim[i].second);
        }
    }
    cout << "-1\n";
    /*
    A
    B
    C

    AA
    BC

    A -> 0, normal (x . y)
      -> 0, flip (y . x)
    */

    return 0;
}
