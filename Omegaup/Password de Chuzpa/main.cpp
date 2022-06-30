#include <iostream>
#define MAXQ 100000
#define left_child (2*node)+1
#define right_child (2*node)+2
#define mid ((left+right)/2)
using namespace std;
int N, Q, Type[MAXQ], Left[MAXQ], Right[MAXQ], Change[MAXQ], Lazy[8*MAXQ], lindex;
char Tree[8*MAXQ];
string Key, Ans;

void Upd(int index, int val) {
	Left[index]+= (val-1);
	Right[index]+= (val-1);
}

char retvalue(int node) {
	return (((Tree[node]-'a')+Lazy[node])%26)+'a';
}

void Create(int node, int left, int right) {
	if(left == right) {
		Tree[node] = Key[left];
		return;
	}
	Create(left_child, left, mid);
	Create(right_child, mid+1, right);
}

void Update(int node, int left, int right, int index) {
	if(left > Right[index] || right < Left[index])
		return;
	if((Left[index] <= left && Right[index] >= right) || left == right) {
		Lazy[node]+= (Change[index]%26);
		Lazy[node]%= 26;
		return;
	}
	Update(left_child, left, mid, index);
	Update(right_child, mid+1, right, index);
}

char Query(int node, int left, int right, int index) {
	if(Lazy[node] && left < right) {
		Lazy[left_child] = (Lazy[left_child]+Lazy[node])%26;
		Lazy[right_child] = (Lazy[right_child]+Lazy[node])%26;
		Lazy[node] = 0;
	}
	if(left == right)
		return retvalue(node);
	if(mid >= index)
		return Query(left_child, left, mid, index);
	else
		return Query(right_child, mid+1, right, index);
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	cin >> Key;
	for(int i=0; i<Q; i++) {
		cin >> Type[i];
		if(Type[i] == 1)
			cin >> Left[i] >> Right[i] >> Change[i];
	}
	for(int i=0; i<MAXQ; i++)
		Key+= "a", N++;
	Create(0, 0, N-1);
	for(int i=0; i<Q; i++) {
		if(Type[i] == 1)
			Upd(i, lindex), Update(0, 0, N-1, i);
		if(Type[i] == 2)
			Ans+= Query(0, 0, N-1, lindex++);
	}
	cout << Ans << "\n";
	return 0;
}
