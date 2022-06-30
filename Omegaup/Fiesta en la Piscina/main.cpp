#include "fiesta.h"
int personA, personB, dp[2005];
bool aKnowsB, bKnowsA;

int isCool(int person, int n) {
	for(int i=1; i<=n; i++)
		if(i!= person && Preguntar(person, i))
			return 0;
	return person;
}

int BusquedaCool(int n) {
	if (n == 1) return 1;
	personA = 1, personB = 1;
	for(int i=0; i<n; i++) {
		if(personA == personB) personB++;
		if(dp[personA]) personA = personB+1;
		if(dp[personB]) personB = personA+1;
		if(personA>n && personB>n) return 0;
		if(personA>n) return isCool(personB, n);
		if(personB>n) return isCool(personA, n);
		aKnowsB = Preguntar(personA, personB);
		bKnowsA = Preguntar(personB, personA);
		if(aKnowsB == bKnowsA)
			personA++, personB++;
		else if(aKnowsB && !bKnowsA)
			dp[personA++] = 1;
		else if(bKnowsA && !aKnowsB)
			dp[personB++] = 1;
	}
	return 0;
}
