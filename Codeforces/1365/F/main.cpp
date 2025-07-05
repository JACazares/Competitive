#include<bits/stdc++.h>
using namespace std;
#define letsgoUltraInstinct ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int

signed main()
{
    letsgoUltraInstinct;
    //cout<<"I must do it......Yeahhh!!!";

    int tt=1;   
    cin>>tt;
    int kk=0;
    pp:
    for(;kk<tt;kk++)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n),c,d;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        c=a,d=b;
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());

        if(c!=d)
        {
            cout<<"No\n";
            kk++;
            goto pp;
        }
        else
        {
            if(n%2==1 && a[n/2]!=b[n/2])
            {
                cout<<"No\n";
                kk++;
                goto pp;
            }
            else
            {
                multiset<pair<int,int>>sa,sb;
                for(int i=0;i<n/2;i++)
                    sa.insert({min(a[i],a[n-i-1]),max(a[i],a[n-i-1])}),sb.insert({min(b[i],b[n-1-i]),max(b[i],b[n-1-i])});
                if(sa==sb)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
            }
        }

    }
    cerr<<"[Execution : "<<(1.0*clock())/CLOCKS_PER_SEC<<"s]\n";
    return 0;
}
