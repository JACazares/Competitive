#include <iostream>
using namespace std;
typedef long long int lld;
int Father, Mother, Son, Masha, sizeMasha;
int ans1, ans2, ans3;

int main () {
	cin >> Father >> Mother >> Son >> Masha;
	for(int sizeFather = Father; sizeFather <= 2*Father; sizeFather++) {
		for(int sizeMother = Mother; sizeMother <= 2*Mother; sizeMother++) {
			for(int sizeSon = Son; sizeSon <= 2*Son; sizeSon++) {
				sizeMasha = 2*Masha;
				if(sizeFather > sizeMother && sizeMother > sizeSon) {
					if(sizeMasha >= sizeSon && sizeMasha < sizeMother && sizeMasha < sizeFather) {
						if(Masha <= sizeSon && Masha <= sizeMother && Masha <= sizeFather) {
							ans1 = sizeFather, ans2 = sizeMother, ans3 = sizeSon;
							cout << ans1 << "\n" << ans2 << "\n" << ans3 << "\n";
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "-1\n";
	return 0;
}
