#include <iostream>
#include <vector>
#include <queue>
#define pb push_back

using namespace std;
using pii = pair<int, int>;

const int MAXN = (int)2e5 + 5;
int N, a[MAXN];
vector<int> graph[MAXN];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        if(i - a[i] >= 0)graph[i - a[i]].pb(i);

        if(i + a[i] < N)
            graph[i + a[i]].pb(i);
    }

    vector<int> ans(N, -1);

    queue<pii> even_queue;
    vector<bool> even_visited(N, false);
    for(int i = 0; i < N; i++)
        if(a[i] % 2 == 0)
        {
            even_visited[i] = true;
            even_queue.push({i, 0});
        }
    
    while(!even_queue.empty())
    {
        int node = even_queue.front().first;
        int even_distance = even_queue.front().second;
        even_queue.pop();

        if(even_distance < 0)
            ans[node] = -even_distance;
        
        for(int next : graph[node])
            if(!even_visited[next])
            {
                even_visited[next] = true;
                even_queue.push({next, even_distance - 1});
            }
    }

    queue<pii> odd_queue;
    vector<bool> odd_visited(N, false);
    for(int i = 0; i < N; i++)
        if(a[i] % 2 == 1)
        {
            odd_visited[i] = true;
            odd_queue.push({i, 0});
        }
    
    while(!odd_queue.empty())
    {
        int node = odd_queue.front().first;
        int odd_distance = odd_queue.front().second;
        odd_queue.pop();

        if(odd_distance < 0)
            ans[node] = -odd_distance;
        
        for(int next : graph[node])
            if(!odd_visited[next])
            {
                odd_visited[next] = true;
                odd_queue.push({next, odd_distance - 1});
            }
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}