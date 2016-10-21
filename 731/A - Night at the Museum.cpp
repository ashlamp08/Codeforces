// $-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$ //
//                                      ashlamps08                                         //
// $-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$ //

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<ld,ld>
#define sf(a) scanf("%d",&a)
#define pf(a) scanf("%d",a)

const int inf = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    string S;

    cin>>S;

    char x = 'a';

    ll ans = 0;

    for(auto a: S)
    {
       if(a>x)
            ans += min((ll)(a-x),(ll)(26 - a + x));
        else
            ans += min((ll)(x-a),(ll)(26 - x + a));
       x =a;
    }

    cout<<ans;

    return 0;
}