//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 300005
#define pii pair < i64 , i64 >
#define fi first
#define se second
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

i64 Q, N, rnd;
i64 a[MAX];
i64 to[MAX], dp[MAX], to2[MAX];
i64 vis[MAX];

void calc( i64 pos ) {
    if( to2[pos] )
        return;
    if( ! to2[pos] )
        to2[pos] = to[pos];
    
    if( to2[pos] + 1 <= N && vis[to2[pos] + 1] == rnd ) {
        calc( to2[pos] + 1 );
        to2[pos] = to2[to2[pos] + 1];
    }
}


void solve( i64 ini ) {
    stack < pii > s;
    s.push( { a[ini] , ini } );
    i64 pos = ini + 1;
    while( ! s.empty() && pos <= N ) {
        if( s.top().fi == a[pos] ) {
            to[s.top().se] = pos;
            vis[s.top().se] = rnd;
            s.pop();
            pos++;
        }
        else if( vis[pos] == rnd ) {
            calc( pos );
            pos = to2[pos] + 1;
        }
        else {
            s.push( { a[pos] , pos } );
            pos++;
        }
    }
    
    while( ! s.empty() ) {
        vis[s.top().se] = rnd;
        to[s.top().se] = N + 1;
        s.pop();
    }
}

int main()
{
    optimiza_io
    cin >> Q;
    while( Q -- ) {
        cin >> N;
        for( i64 i = 1; i <= N; i ++ )
            cin >> a[i];
        
        rnd++;
        for( i64 i = 1; i <= N; i ++ )
            if( vis[i] != rnd ) 
                solve( i );
             
        i64 ans = 0;   
        for( i64 i = N; i >= 1; i -- ) {
            if( to[i] <= N ) 
                dp[i] = dp[to[i] + 1] + 1;
            ans += dp[i];
        }
        
        cout << ans << "\n";
        
        // Clear
        for( i64 i = 1; i <= N; i ++ )
            to[i] = dp[i] = to2[i] = 0;
    }
    return 0;
}
