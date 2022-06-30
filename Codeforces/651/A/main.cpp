#include <iostream>
using namespace std;
long long int J1, J2, MaxTime;

int main()
{
	cin >> J1 >> J2;
	while( J1 > 0 && J2 > 0 )
	{
		if( J1 == 1 && J2 == 1)
			break;
		if(J1 > J2)
		{
			J2+= 1;
			J1-= 2;
		}
		else {
			J1+= 1;
			J2-= 2;
		}
		MaxTime++;
	}
	cout << MaxTime << "\n";
	return 0;
}
