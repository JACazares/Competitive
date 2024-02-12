#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
  int N;
  cin >> N;
  vector<int> a(2*N);
  for(int i = 0; i < 2*N; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  cout << a[N - 1] - a[0] + a[2*N - 1] - a[N] << "\n";
  for(int i = 0; i < N; i++)
    cout << a[i] << " " << a[N + i] << "\n";
}

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}