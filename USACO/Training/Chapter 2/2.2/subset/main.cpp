/*
ID: josecaz1
PROG: subset
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lld;
ifstream fin("subset.in");
ofstream fout("subset.out");
int N, dp[40][1000];

int solve(int cnt, int sum) {
	if(sum == (N*(N+1))/4)
		return 1;
	if(cnt == N || sum >= (N*(N+1)/4))
		return 0;
	if(dp[cnt][sum])
		return dp[cnt][sum];
	dp[cnt+1][sum+cnt] = solve(cnt+1, sum+cnt);
	dp[cnt+1][sum] = solve(cnt+1, sum);
	return dp[cnt][sum] = dp[cnt+1][sum+cnt] + dp[cnt+1][sum];
}

int main () {
	fin >> N;
	if((N*(N+1))/2 % 2 == 0)
		fout << solve(1, 0) << "\n";
	else
		fout << "0\n";
	return 0;
}
