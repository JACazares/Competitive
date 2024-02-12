#include<iostream>
#include <vector>
#include<string>
#define ll long long
using namespace std;
const ll L = (1 << 24);
ll fx[1000];
ll fy[1000];
ll solve1(ll x, ll y, string s){
  ll max_x = 0 , min_x = 0, max_y = 0, min_y = 0;
  ll cx = 0, cy  = 0;
  for(ll i = 0; i < s.size(); i++){
    cx += fx[s[i]];
    cy += fy[s[i]];
    min_x = min(min_x, cx);
    max_x = max(max_x, cx);
    min_y = min(min_y, cy);
    max_y = max(max_y, cy);

  }
  ll t = 0;
  while(1){
    if(x + min_x < 0 || 
       x + max_x >= L ||
       y + min_y < 0 || 
       y + max_y >= L) break;
       t+= s.size();
       x += cx;
       y += cy;
  }
  for(ll i = 0; i < s.size(); i++){
    x += fx[s[i]];
    y += fy[s[i]];
  if(x < 0 || 
       x >= L ||
       y < 0 || 
       y>= L) return t + i + 1;
  }


}
ll solve2(ll x, ll y, string a, string b){
  if(x == 0 && y == 0) return 0;
  ll cx = 0 , cy = 0;
  vector<pair<ll,ll> > v;
  for(ll i = 0; i < a.size(); i++){
    cx += fx[a[i]] - fx[b[i]];
    cy += fy[a[i]] - fy[b[i]];
    v.push_back({cx, cy});
  }
  ll t = 1e18;
  for(ll i = 0; i < v.size(); i++){
    ll xi = v[i].first, yi = v[i].second;
      ll dx = -xi - x;
      ll dy = -yi - y;
      if(cx && cy && dx % cx == 0 && dy  % cy == 0 && dx % cx == 0 && dy / cy == dx / cx && dx/cx >= 0){
        t = min(t, (dx / cx) * (ll)v.size() + i + 1);
      }
      if(cx && !cy && dy == 0 && dx % cx == 0 && dx / cx >= 0){
        t = min(t, (dx / cx) * (ll)v.size() + i + 1);
      }
      if(cy && !cx && dx == 0 && dy % cy == 0 && dy / cy >= 0){
        t = min(t, (dy/cy) * (ll)v.size() + i + 1);
      
    }
  }
  return t;
}
int main(){
  fx['N'] = 0; fy['N'] = 1;
  
  fx['E'] = 1; fy['E'] = 0;
  fx['W'] = -1; fy['W'] = 0;
  fx['S'] = 0; fy['S'] = -1;
  ll x1, y1;
  ll x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll K;
  cin >> K;
  string a, b;
  cin >> a >> b;
  ll s1 = solve1(x1, y1, a);
  ll s2 = solve1(x2, y2, b);
  ll s3 = solve2(x1-x2, y1-y2, a, b);
  if(s1 == s2 && s1 <= s3){
    cout << "Both robots fall off the board at time "<<s1<<"."<<endl;
  }
  else if(s1 < s2 && s1 <= s3){
    cout << "Robot 1 falls off the board at time "<<s1<<"."<<endl;
  }
  else if (s2 < s1 && s2 <= s3){

    cout << "Robot 2 falls off the board at time "<<s2<<"."<<endl;
  }
  else cout << "The two robots collide at time "<<s3<<"."<<endl;
}