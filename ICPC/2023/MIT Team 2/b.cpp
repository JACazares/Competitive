#include<iostream>
#include<vector>
using namespace std;
int r[20][20];
int f[20][20];
int dp[66000][17][5];
int mh[66000];
int sz[66000];
vector<int> v[100009];
int main(){
  int n, m;
  cin >> n >> m;
  m--;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> r[i][j];
      //if(i > j) r[i][j] = 1;
      if(r[i][j] == 1) f[i][j] = i;
      else f[i][j] = j;
    }
  }
  for(int b = 0; b < (1 << n); b++){
    int x= __builtin_popcount(b);
  int d = 0, l = 1;
  while(l < x) d++, l*=2;
  mh[b] = d;
    if((1<<m) & b) v[b].push_back(m); else
    for(int i = 0; i < n; i++){
      if((1<<i) & b) v[b].push_back(i);

    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 4; j++)
    dp[(1<<i)][i][j] = 1;
  }
  int H = mh[(1<<n)-1];
  
  for(int b = 0; b < (1 << n); b++){
    if(__builtin_popcount(b) <= 1) continue;
    int mx;
    if(b != (1<<n)-1) mx = H-1;
    else mx = H;
    for(int b1 = (b-1)&b; b1 > b / 2; b1 = b&(b1-1)){
      int b2 = b - b1;
      
      for(int h = mh[b]; h <= mx; h++)
      for(int i:v[b1])
        for(int j:v[b2]){
          dp[b][f[i][j]][h] += dp[b1][i][h-1] * dp[b2][j][h-1];
        }
    }
  }
  cout << dp[(1<<n)-1][m][H] << endl;



}