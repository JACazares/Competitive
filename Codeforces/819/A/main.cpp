#include <iostream>
using namespace std;
typedef long long int lld;
lld a, b, l, r, ans;
bool bucket[30];
string s;

string createSequence(string k) {
	for(int i=0; i<a; i++)
		k+= i+'a';
	for(int i=0; i<b; i++)
		k+= k[a-1];
	if(b > a) {
		for(int i=0; i<a-1; i++)
			k+= i+'a';
		k+= a+'a';
	} else {
		bool B[30];
		for(int i=0; i<30; i++)
			B[i] = 0;
		for(int i=k.length()-a; i< k.length(); i++) {
			B[k[i]-'a']=1;
		}
		for(int i=0; i<a; i++) {
			for(int j=0; j<26; j++) {
				if(!B[j]) {
					k+= j+'a';
					B[j]=1;
					break;
				}
			}
		}
	}
	for(int i=0; i<b; i++)
		k+= k[(2*a)+b-1];
	return k;
}

int main () {
	cin >> a >> b >> l >> r;
	if(r-l+1 >= 2*(a+b)) {
		if(b>=a)
			ans = a+1;
		else
			ans = (2*a)-b;
	} else {
		l%= 2*(a+b);
		r%= 2*(a+b);
		if(r<= l)
			r+= 2*(a+b);
		s = createSequence("");
		s+= createSequence("");
		for(int i=l-1; i<r; i++)
			bucket[s[i]-'a'] = 1;
		for(int i=0; i<26; i++)
			if(bucket[i])
				ans++;
	}
	cout << ans << "\n";
	return 0;
}
