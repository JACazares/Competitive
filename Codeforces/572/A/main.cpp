#include <iostream>

using namespace std;

int main()
{
    int nA = 0, nB = 0, k = 0, m = 0;
    cin >> nA >> nB;
    cin >> k >> m;
    int A[nA], B[nB], numA[k], numB[m];
    for (int i = 0; i < nA; i++){
        cin >> A[i];
    }
    for (int i = 0; i < nB; i++){
        cin >> B[i];
    }
    for (int i = 0; i < k; i++){
        numA[i] = A[i];
    }
    for (int i = 0; i < m; i++){
        numB[i] = B[nB-(i+1)];
    }
    if (numA[k-1] < numB[m-1]){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
