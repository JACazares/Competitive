#include <bits/stdc++.h>
#define MAXN 100000
#define MAXT 40000000
using namespace std;
struct node {
	int child[2];
};
long long int N, A[MAXN+5], Prefix[MAXN+5], Suffix[MAXN+5], ans;
stack<bool> Binary;
node Trie[MAXT];
int m=0;

string Convert(long long int a) {
	//Convert an integer to a 40-bit binary number
	string s;
	bool b;
	char c;
	while(a > 0) {
		Binary.push(a%2);
		a/= 2;
	}
	while(Binary.size() < 40)
		Binary.push(0);
	while(!Binary.empty()) {
		b = Binary.top();
		c = (char)(b+'0');
		s+= c;
		Binary.pop();
	}
	return s;
}

long long int Convert2(string s) {
	long long int a=0;
	for(int i=0; i<s.length(); i++)
	{
		a*= 2;
		a+= (int)(s[i]-'0');
	}
	return a;
}

long long int Compare(string s) {
	//Look for the biggest difference, bit wise
	//  e.g. if my number is 100010101
	//
	//	and I have 2 options 111101010
	//                   and 000010101
	//  Then this function should return 100010101^00001010 because
	//		the xor would be maximized. Look for the different bit.
	int pos = 0;
	char c;
	string bin;
	for(int i=0; i<s.length(); i++)
	{
		int l = s[i]-'0';
		int l1 = (l+1)%2;
		if(!Trie[pos].child[l1]) {
			c = (char)(l+'0');
			bin+= c;
			pos = Trie[pos].child[l];
		}
		else {
			c = (char)(l1+'0');
			bin+= c;
			pos = Trie[pos].child[l1];
		}
	}
	return Convert2(s)^Convert2(bin);
}

void Add(string s) {
	//Add string s (40-bit binary number) to the trie
	int pos = 0;
	for(int i=0; i<s.length(); i++)
	{
		int l = s[i]-'0';
		if(!Trie[pos].child[l])
			Trie[pos].child[l] = ++m;
		pos = Trie[pos].child[l];
	}
}

//Basic Functions
void GetInput() {
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> A[i];
}

void PrefixTable() {
	//Create Prefix Table
	Prefix[0] = 0;
	for(int i=1; i<=N; i++)
		Prefix[i] = Prefix[i-1]^A[i];
}

void SuffixTable() {
	//Create Suffix Table
	Suffix[N+1] = 0;
	for(int i=N; i>=1; i--)
		Suffix[i] = Suffix[i+1]^A[i];
}

void SolveProblem() {
	//Compare all of the prefixes (right to left) with
	//  all of the suffixes that don't overlap
	PrefixTable();
	SuffixTable();
	for(int i=N; i>=0; i--) {
		Add(Convert(Suffix[i+1]));
		ans = max(ans, Compare(Convert(Prefix[i])));
	}
}

void PrintOutput() {
	cout << ans << "\n";
}

int main() {
	GetInput();
	PrefixTable();
	SuffixTable();
	SolveProblem();
	PrintOutput();
	return 0;
}
