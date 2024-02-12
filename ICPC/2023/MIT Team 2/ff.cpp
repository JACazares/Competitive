#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int x, int y){
  if(y == 0) return x;
  return gcd(y, x%y);
}
int main(){
  int x, y;
  cin >> x >> y;
  x %= y;
  int g = gcd(x, y);
  x /= g;
  y /= g;
  if(x == 0){
    cout <<0 <<" "<<0<<endl;
    return 0;
  }
  int x2 = 0, x5 = 0;
  while(y % 2 == 0)
    y /= 2, x2++;
  while(y%5 == 0)
    y /= 5, x5++;
  cout << max(x2, x5)<<" ";
  int z = 10 % y, c= 1;
  if(y == 1){
    cout << 0 << endl;
  }
  else{
    while(z != 1)
      z = z * 10 % y,
      c++;
    cout << c << endl;
  }


}