#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int x[10009], y[10009];
double dp[1009];
double dist(double x1, double y1, double x2, double y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double calc(double x1, double y1, double x2, double y2, double y){
  return (x1 * (y2 - y) + x2 * (y - y1) )/ (y2 - y1);
}
int main(){
  int n;
  cin >> n;
  int v1, v2;
  cin >> v1 >> v2;
  for(int i = 1; i <= n; i++){
    cin >> x[i] >> y[i];
  }
  dp[1] = 0;
  for(int i = 2; i <= n; i++){
    int mn = y[i-1];
    dp[i] = dp[i-1] + dist(x[i-1], y[i-1], x[i], y[i]) / v1;
    int ok = 1;
    if(mn <= y[i]) ok = 0;
    for(int j = i - 2; j >= 1; j--){
      mn = min(mn, y[j]);
      if(ok && mn == y[j] && y[j] > y[i]){
        if(j < i - 1 && y[j] <= y[i-1]){
          double xm = calc(x[i-1], y[i-1], x[i], y[i], y[j]);
          dp[i] = min(dp[i], dp[j] + (xm - x[j]) /v2  + dist(xm, y[j], x[i], y[i]) / v1);
        }
       // cout << i <<" -- " << j <<endl;
      }
      else if(ok && mn == y[j] && y[j] <=y[i]){
        ok = 0;
        if(j < i - 1 && y[i] <= y[j+1]){
          double xm = calc(x[j], y[j], x[j+1], y[j+1], y[i]);
          dp[i] = min(dp[i], dp[j] + dist(x[j], y[j], xm, y[i]) / v1 + (x[i] - xm)/v2);
        }
       // cout << i <<" -- " << j <<endl;
      }
    }
   // cout << i <<" " <<dp[i]<<endl;
  }
  printf("%.9f\n", dp[n]);
  
}