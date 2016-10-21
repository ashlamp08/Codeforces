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

    map<string, int> m;

    m["monday"] = 0;
    m["tuesday"] = 1;
    m["wednesday"] = 2;
    m["thursday"] = 3;
    m["friday"] = 4;
    m["saturday"] = 5;
    m["sunday"] = 6;

    string s1,s2;
    cin>>s1>>s2;

    int a = m[s1];
    int b = m[s2];

    if((b%7 == (a+3)%7) || (b%7 == (a+2)%7) || (b%7 == (a)%7))
        cout<<"YES";
    else
        cout<<"NO";


    return 0;
}