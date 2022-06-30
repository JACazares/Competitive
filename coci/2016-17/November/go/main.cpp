#include <iostream>
using namespace std;
int Num_Pokemons, Required[70], Food[70], Evolutions, MaxEvolutions, Evolved;
string Pokemon[70], MaxPokemon;

int main() {
	cin >> Num_Pokemons;
	for(int i=0; i<Num_Pokemons; i++)
		cin >> Pokemon[i] >> Required[i] >> Food[i];
	for(int i=0; i<Num_Pokemons; i++) {
		while(Food[i] >= Required[i]) {
			Food[i]-= Required[i];
			Food[i]+= 2;
			Evolutions++;
			Evolved++;
		}
		if(Evolutions > MaxEvolutions) {
			MaxEvolutions = Evolutions;
			MaxPokemon = Pokemon[i];
		}
		Evolutions = 0;
	}
	cout << Evolved << "\n" << MaxPokemon << "\n";
	return 0;
}
