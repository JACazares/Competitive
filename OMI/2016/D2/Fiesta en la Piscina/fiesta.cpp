#include "fiesta.h"
#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

// Main
//	int Preguntar(int a, int b)

vector<int> candidatos, nuevos_candidatos;

int BusquedaCool(int N)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	candidatos.clear();
	for(int i = 1; i <= N; i++)
		candidatos.pb(i);

	while(candidatos.size() > 1)
	{
		nuevos_candidatos.clear();
		for(int i = 0; i < candidatos.size(); i += 2)
		{
			if(i + 1 >= candidatos.size())
			{
				nuevos_candidatos.push_back(candidatos[i]);
				continue;
			}

			int direccion_de_amistad = Preguntar(candidatos[i], candidatos[i + 1]);
			if(direccion_de_amistad == -1)
				return 0;

			if(direccion_de_amistad == 1)
			{
				// A conoce a B -- B puede ser el cool, A no
				nuevos_candidatos.pb(candidatos[i + 1]);
			}
			else
				nuevos_candidatos.pb(candidatos[i]);
		}

		swap(candidatos, nuevos_candidatos);
		nuevos_candidatos.clear();
	}

	int chico_cool = candidatos[0];
	for(int i = 1; i <= N; i++)
	{
		if(i == chico_cool)
			continue;

		int direccion_de_amistad = Preguntar(i, chico_cool);
		if(direccion_de_amistad == -1)
			return 0;
		if(direccion_de_amistad == 0)
			return 0;
	}
	
	return chico_cool;
}