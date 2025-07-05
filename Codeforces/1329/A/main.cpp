#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 1e5+5;
ll N, M, sum, currMax, p[MAXN], aux[MAXN];
pii l[MAXN];

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M;
	for(ll i = 0; i < M; i++)
    {
        cin >> l[i].first;
        l[i].second = i;
        sum += l[i].first;
    }
    reverse(l, l+M);
    currMax = l[0].first;
    p[l[0].second] = 1;
    for(ll i = 1; i < M; i++)
    {
        if(l[i].first <= currMax)
            ++currMax;
        else
            currMax = l[i].first;
        p[l[i].second] = currMax - l[i].first + 1;
    }
    
    if(currMax <= N && N <= sum)
    {
        N -= currMax;
        for(ll i = 0; i < M; i++)
        {
            if(i > 0)
            {
                p[l[i].second] += aux[i - 1];
                aux[i] += aux[i - 1];
            }
            aux[i] += min(l[i].first, N - aux[i]);
        }
        for(ll i = 0; i < M; i++ )
            cout << p[i] << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";
	return 0;
}
