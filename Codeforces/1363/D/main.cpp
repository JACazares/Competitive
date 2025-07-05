#include<bits/stdc++.h>
#include <chrono>
#include<math.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std::chrono;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// declaration: ordered_set os;  methods->  1. *os.find_by_order(x)   2. os.order_of_key(k) ->return int

#define fr(x,i,n) for(int x = i; x < n; ++x)
#define fb(x,i,n) for(int x = i; x >= n; --x)
#define pr pair<int,int>
#define ll long long int
#define ld long double
const ll mod=998244353;
ll f(ll x,ll n){
    ll r=1;
    while(n){
        if(n&1)
        r=(r*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return r;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> adj[k];
    fr(i,0,k){
        int c;
        cin>>c;
        fr(j,0,c){
            int x;
            cin>>x;
            adj[i].push_back(x);
        }
    }
    cout<<"? "<<n<<" ";
    fr(i,1,n+1)
    cout<<i<<" ";
    cout<<endl;
    ll mx;
    cin>>mx;
    if(mx==-1) exit(0);
    int max_index;
    int l=1,h=n,mid;
    while(l<h){
        mid=(l+h)/2;
        cout<<"? ";
        cout<<mid+1-l<<" ";
        fr(i,l,mid+1)
        cout<<i<<" ";
        cout<<endl;
        ll x;
        cin>>x; if(x==-1) exit(0);
        if(x==mx){
            h=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l>n||h<1)
    exit(0);
    max_index=l;
    ll a[k];
    fr(i,0,k){
        bool f=0;
        fr(j,0,adj[i].size()){
            if(adj[i][j]==max_index)
            f=1;
        }
        if(!f){
            a[i]=mx;
        }
        else{
            cout<<"? "<<n-adj[i].size()<<" ";
            sort(adj[i].begin(),adj[i].end());
            int j=0,ask=1;
            while(ask<=n){
                if(j < adj[i].size() && adj[i][j]==ask){
                    ask++;
                    j++;
                }
                else{
                    cout<<ask<<" ";
                    ask++;
                }
            }
            cout<<endl;
            ll x;
            cin>>x; if(x==-1) exit(0);
            a[i]=x;
        }
    }
    cout<<"! ";
    fr(i,0,k)
    cout<<a[i]<<" ";
    cout<<endl;
    string s;
    cin>>s;
    if(s!="Correct")
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    build();
    int t=1;
    cin>>t;
    while(t--)
    solve();

}
