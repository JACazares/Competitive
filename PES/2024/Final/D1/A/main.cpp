#include <iostream>
#include "arbol.cpp"

int main()
{
	std::cin >> N;
	std::vector<int> u(N, 0), v(N, 0), w(N, 0);
	for(int i = 0; i < N; i++)
		std::cin >> u[i] >> v[i] >> w[i];
		
	std::cout << Encuentra_xor(N, u, v, w) << "\n";
	return 0;
}
