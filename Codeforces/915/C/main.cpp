#include <iostream>
using namespace std;
typedef long long int lld;
string A, B, ans;
int bucketA[10], bucketB[10], aux, auxI;

string maxPerm() {
	string ret = "";
	for(int i = 9; i >= 0; i--)
		for(int j = 0; j < bucketA[i]; j++)
			ret+= (i + '0');
	return ret;
}

int main () {
	cin >> A >> B;
	for(int i = 0; i < A.length(); i++)
		bucketA[A[i] - '0']++;
	for(int i = 0; i < B.length(); i++)
		bucketB[B[i] - '0']++;
	if(B.length() > A.length()) {
		cout << maxPerm();
	} else {
		for(int i = 0; i < B.length(); i++) {
			aux = -1;
			for(int j = 0; j < A.length(); j++)
				if(A[j] <= B[i] && (aux == -1 || A[j] >= A[aux]) && bucketA[A[j] - '0'] >= 1)
					aux = j;
			if(aux == -1) {
				auxI = i;
				break;
			}
			bucketA[A[aux] - '0']--;
			ans+= A[aux];
			if(A[aux] < B[i]) {
				ans+= maxPerm();
				break;
			}
		}
		if(aux == -1) {
			for(int i = auxI - 1; i >= 0; i--) {
				aux = -1;
				for(int j = 0; j < A.length(); j++)
					if(A[j] < B[i] && (aux == -1 || A[j] >= A[aux]) && bucketA[A[j] - '0'] >= 1)
						aux = j;
				if(aux == -1) {
					bucketA[ans[i] - '0']++;
					continue;
				}
				bucketA[ans[i] - '0']++;
				bucketA[A[aux] - '0']--;
				for(int k = 0; k < i; k++)
					cout << ans[k];
				cout << A[aux] << maxPerm() << "\n";
				return 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
