#include <bits/stdc++.h>
using namespace std;
long long int N, A[100], temp;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N-1; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
                cout << j+1 << " " << j+2 << "\n";
            }
        }
    }
    return 0;
}
