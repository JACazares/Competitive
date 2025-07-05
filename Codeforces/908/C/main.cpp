#include <iostream>
#include <iomanip>
#define MAXN 1005
#define MAX 10000000000
using namespace std;
typedef long long int lld;
int N, R, coordX[MAXN], id1, id2;
double ans[MAXN];

double Abs(double a) {
	if(a < 0)
		return -a;
	return a;
}

bool touches(double x1, double y1, double x2, double y2) {
	if((Abs(x1 - x2) * Abs(x1 - x2)) + (Abs(y1 - y2) * Abs(y1 - y2)) <= 4*R*R)
		return true;
	return false;
}

double binary(double Left, double Right, int Iterations) {
	double mid = (Left + Right)/2;
	if(Iterations == 40)
		return mid;
	bool val = !touches(coordX[id1], ans[id1], coordX[id2], mid);
	if(val)
		return binary(Left, mid, Iterations+1);
	else
		return binary(mid, Right, Iterations+1);
}

double solve(int idx) {
	double ret = R;
	for(int i = 0; i < idx; i++) {
		if(Abs(coordX[i] - coordX[idx]) > 2*R)
			continue;
		id1 = i, id2 = idx;
		ret = max(ret, binary(ans[i], ans[i]+(2*R), 0));
	}
	return ret;
}

int main () {
	cin >> N >> R;
	for(int i = 0; i < N; i++)
		cin >> coordX[i];
	for(int i = 0; i < N; i++) {
		ans[i] = solve(i);
		cout << fixed << setprecision(9) << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
