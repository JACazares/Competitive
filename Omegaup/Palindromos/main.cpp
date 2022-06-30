#include <iostream>
using namespace std;
int N;
bool Vis[25][25];
string S, i;
string DP[25][25];

string minimum(string a, string b) {
	if(a.length() < b.length()) return a;
	else if(b.length() < a.length()) return b;
	else return min(a, b);
}

string Palindrome(int l, int r) {
	if(Vis[l][r])  return DP[l][r];
	i = S[l];
	Vis[l][r] = 1;
	if(l > r)  return DP[l][r] = "";
	if(l == r)  return DP[l][r] = i;
	if(S[l] == S[r])  return DP[l][r] = S[l]+Palindrome(l+1, r-1)+S[r];
	return DP[l][r] = minimum(S[l]+Palindrome(l+1, r)+S[l], S[r]+Palindrome(l, r-1)+S[r]);
}

int main ()
{
	cin >> S;
	cout << Palindrome(0, s.length()-1) << "\n";
	return 0;
}
