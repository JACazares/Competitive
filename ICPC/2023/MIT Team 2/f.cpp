#include <iostream>
#include <map>

using namespace std;

int a, b;
map<int, int> mp, dp, zeroes;

int main() {
  cin >> a >> b;
  a -= (a/b)*b;
  bool borrowed = false;
  int ans = 0, qttZeroes = 0;
  while(mp.find(a) == mp.end()){
    if(a == 0) {
      cout << ans << " " << 0 << endl;
      exit(0);   
    }
    int savea = a;
    if(a < b){
      if(borrowed) {
        
      }
    }
  }

  int k = a;
  int ans2 = 0;
  do {
    ans2 += 1+zeroes[k];
    k = mp[k];
  } while(k != a);
  cout << dp[a] << " " << ans2-zeroes[a] << endl;
}