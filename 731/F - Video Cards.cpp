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

ll BIT[200005]={0};

ll N = 200005;

void add(int i)
{
    while(i<N){
        BIT[i] += 1;
        i += i&-i;
    }
}

ll fetch(int i)
{
    ll res = 0;
    while(i>0){
        res += BIT[i];
        i -= i&-i;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
        add(a[i]);

    set<int> SS;

    for(int i=0;i<n;i++)
        SS.insert(a[i]);

    int last = *(--(SS.end()));

    ll ans = 0;

    for(auto aa: SS)
    {
        ll xx = 0;
        int j;

        for(j=aa;j<=last;j+=aa){
            xx+=(ll)j*(fetch(j) - fetch(j-1));
            xx+=(ll)(j-aa)*(fetch(j-1)-fetch(j-aa));
        }
        xx+=(ll)(j-aa)*(fetch(200003)-fetch(j-aa));
        ans = max(ans,xx);
    }

    cout<<ans;

    return 0;
}