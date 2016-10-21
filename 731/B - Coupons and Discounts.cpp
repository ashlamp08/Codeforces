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

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    int add = 0;

    for(int i=0;i<n;i++)
    {
        if(add)
            a[i]--;

        if(a[i]<0)
        {
            cout<<"NO";
            return 0;
        }

        add = a[i]%2;
    }

    if(add)
        cout<<"NO";
    else
        cout<<"YES";

    return 0;
}