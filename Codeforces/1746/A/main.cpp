#include <iostream>

using namespace std;

void solve()
{
  int N, K;
  cin >> N >> K;
  bool ans = 0;
  for(int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    if(a == 1)
      ans = 1;
  }

  cout << (ans ? "YES" : "NO") << "\n";
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
