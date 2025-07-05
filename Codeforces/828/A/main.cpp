#include <iostream>
using namespace std;
typedef long long int lld;
int N, OnePerson, TwoPeople, OccupiedTwoPeople, t, Denied;

int main () {
	cin >> N >> OnePerson >> TwoPeople;
	for(int i=0; i<N; i++) {
		cin >> t;
		if(t == 2) {
			if(TwoPeople == 0)
				Denied+= t;
			else
				TwoPeople--;
		} else if(t == 1) {
			if(OnePerson == 0 && TwoPeople == 0 && OccupiedTwoPeople == 0)
				Denied+= t;
			if(OccupiedTwoPeople > 0)
				OccupiedTwoPeople--;
			else if(OnePerson > 0)
				OnePerson--;
			else if(TwoPeople > 0)
				TwoPeople--, OccupiedTwoPeople++;
		}
	}
	cout << Denied << "\n";
	return 0;
}
