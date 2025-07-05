#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 2e5 + 5;
ll N, M, p[MAXN];
vi Graph[MAXN];

ll put(ll a, ll b, ll c)
{
    //dist, node, pos, parent
    priority_queue<pair<ll, pair<ll, pii>>> PQ;
    ll dist, node, pos, ans = 0;
    vi vis(N + 1, 0), weight(N + 1, 0), par(N + 1, 0), distance(N + 1, 0);
    PQ.push({0, {b, {0, 0}}});
    while(!PQ.empty())
    {
        auto aux = PQ.top();
        PQ.pop();
        dist = aux.first;
        node = aux.second.first;
        pos = aux.second.second.first;
        
        if(vis[node])
            continue;
        vis[node] = 1;
        distance[node] = -dist;
        weight[node] = pos - 1;
        par[node] = aux.second.second.second;

        for(auto i : Graph[node])
            if(!vis[i])
                PQ.push({dist - p[pos], {i, {pos + 1, node}}});
    }

    node = a;
    pos = weight[a] + 1;
    ans = distance[a];
    map<pii, ll> cost;
    while(par[node] != 0)
    {
        cost[{par[node], node}] = p[weight[node]];
        cost[{node, par[node]}] = p[weight[node]];
        node = par[node];
    }

    //dist, node, pos, parent
    vis.clear();
    vis.resize(N + 1);
    PQ.push({0, {b, {pos, 0}}});
    while(!PQ.empty())
    {
        auto aux = PQ.top();
        PQ.pop();
        dist = aux.first;
        node = aux.second.first;
        pos = aux.second.second.first;
        
        if(vis[node])
            continue;
        vis[node] = 1;
        if(node == c)
            break;

        for(auto i : Graph[node])
            if(!vis[i])
            {
                if(!cost[{node, i}])
                    PQ.push({dist - p[pos], {i, {pos + 1, node}}});
                else
                    PQ.push({dist - cost[{node, i}], {i, {pos, node}}});
            }
    }
    return ans - dist;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        ll a, b, c;
        cin >> N >> M >> a >> b >> c;
        for(ll i = 0; i < M; i++)
            cin >> p[i];
        for(ll i = 1; i <= N; i++)
            Graph[i].clear();
        for(ll i = 0; i < M; i++)
        {
            ll u, v;
            cin >> u >> v;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        sort(p, p + M);

        ll ans1 = put(a, b, c);
        ll ans2 = put(c, b, a);
        cout << min(ans1, ans2) << "\n";
    }
    return 0;
}
