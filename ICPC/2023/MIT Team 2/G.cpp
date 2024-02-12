#include<iostream>
#include<vector>

const int MAXN = 3010;
const int inf = 25*MAXN;

using namespace std;

int n, m;
int profit[MAXN];
int dp[MAXN][MAXN], leaves[MAXN];
vector<pair<int,int> > adj[MAXN];

void dfs(int x, int par) {
  for(int i = 1; i <= m; i++) {
    dp[x][i] = -inf;
  }
  if(x > n-m) {
    leaves[x] = 1;
    dp[x][1] = profit[x];
  }
  for(auto &e : adj[x]){
    if(e.first == par) continue;
    dfs(e.first, x);
    for(int j = leaves[x]; j  >= 0; j--) {
      for(int k = leaves[e.first]; k >= 0; k--){
        dp[x][j+k] = max(dp[x][j+k], dp[e.first][k]+dp[x][j]-e.second);
      }
    }
    leaves[x] += leaves[e.first];
  }
  // cout << x << endl;
  // for(int i = 0; i <= m; i++) {
  //   cout << dp[x][i] << " ";
  // }
  // cout << endl;
}

int main() {
  cin >> n >> m;
  for(int i = 1, k; i <= n-m; i++) {
    cin >> k;
    for(int j = 0, a, c; j < k; j++) {
      cin >> a >> c;
      adj[i].push_back(make_pair(a,c));
    }
  }
  for(int i = n-m+1; i <= n; i++) {
    cin >> profit[i];
  }

  dfs(1,-1);

  for(int i = m ; i >= 0; i--) {
    if(dp[1][i] >= 0) {
      cout << i << endl;
      exit(0);
    }
  }
}