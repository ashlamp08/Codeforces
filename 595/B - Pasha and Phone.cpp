#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

#define M 1000000007

ll mod_exp(ll a, ll b, ll c)
{
    ll ans = 1;
    
    while(b)
    {
        if(b&1)
            ans = (ans*a)%c;
            
        a = (a*a)%c;
        b = b>>1;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    
    ll a[(n/k)+2];
    ll b[(n/k)+2];
    
    for(int i=0;i<(n/k);i++)
        cin>>a[i];

    for(int i=0;i<(n/k);i++)
        cin>>b[i];
    
    ll ans = 1;

    ll sth =1;
    
    for(int i=0;i<k-1;i++)
        sth*=10;
   
    for(int i=0;i<(n/k);i++)
    {
        ll x=0; 
        
        if(b[i])
            x = ((b[i]+1)*sth - 1)/a[i] - (b[i]*sth -1)/a[i];
        else
            x = (sth-1)/a[i] + 1;
        
        x = (sth*10-1)/a[i] + 1 - x;
        
        ans = (ans*x)%M;
    }
    
    cout<<ans<<'\n';
    
    return 0;
}