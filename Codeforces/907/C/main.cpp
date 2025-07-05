#include <iostream>
using namespace std;
typedef long long int lld;
int N, ans, x;
char opc, aux;
string w;
bool flag;
bool bucket[26];

int main () {
	cin >> N;
	for(int i = 0; i < 26; i++)
		bucket[i] = 1;
	for(int k = 0; k < N; k++) {
		cin >> opc;
		if(opc == '.') {
			cin.get(aux);
			cin >> w;
			if(!flag) {
				for(int i = 0; i < w.length(); i++)
					bucket[w[i]-'a'] = 0;
				
			}
		} else if (opc == '!') {
			cin.get(aux);
			cin >> w;
			if(flag)
				ans++;
			else {
				bool bucketAux[26];
				for(int i = 0; i < 26; i++)
					bucketAux[i] = 0;
				for(int i = 0; i < w.length(); i++)
					bucketAux[w[i]-'a'] = 1;
				for(int i = 0; i < 26; i++) {
					if(!bucketAux[i])
						bucket[i] = 0;
				}
			}
		} else {
			cin.get(aux);
			cin >> w;
			if(k < N-1) {
				bucket[w[0]-'a'] = 0;
				if(flag)
					ans++;
			}
		}
		x = 0;
		for(int i = 0; i < 26; i++)
			x+= (bucket[i] == 1);
		if(x == 1)
			flag = 1;
	}
	cout << ans << "\n";
	return 0;
}
