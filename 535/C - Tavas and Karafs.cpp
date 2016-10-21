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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    ll a,b,n;

    cin>>a>>b>>n;

    while(n--){
        ll l,t,m;
        cin>>l>>t>>m;

        ll aa = a + b*(l-1);

        if(aa>t)
        {
            cout<<"-1\n";
            continue;
        }

        ll r = l;

        while(m*t>=(((r-l+1)*(aa + a + b*(r-1))/2)) && (a+b*(r-1)<=t)){
            r = r<<1;
        }

        ll low = r>>1;
        ll high = r;
        ll mid = (low+high)/2;

        while(low<=high){

            mid = (low+high)/2;


            ll val = ((mid-l+1)*(aa + a + b*(mid-1))/2);
//            cout<<"mid  "<<mid<<", val : " << val << ", low : " << low
//                << ", high : " << high << endl;


            if(val<=m*t && (a+b*(mid-1)<=t))
            {
//                cout << "\tval[mid + 1] : " << ((m*t>=((mid-l+2)*(aa + a + b*(mid))/2) && (a+b*(mid)<=t))) << endl;
                if(m*t>=((mid-l+2)*(aa + a + b*(mid))/2) && (a+b*(mid)<=t))
                    low = mid+1;
                else
                    break;

            }
            else
                high = mid - 1;
        }

        cout<<mid<<'\n';


    }


    return 0;
}

/*

2 1 4
1 5 3
3 3 10
7 10 2
6 4 8

2 1 1
7 10 2

2 3 1
92947 647140 224508


*/