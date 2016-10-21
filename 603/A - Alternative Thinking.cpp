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

    string s;
    cin>>s;

    string a = "";
    string b = "";

    for(int i=0;i<n;i++){
        a.push_back('0'+(i&1));
        b.push_back('0'+!(i&1));
    }

    //cout<<a<<'\n'<<b<<endl;

    int alt1 = 0;
    int alt2 = 0;
    int mal1 = 0;
    int mal2 = 0;
    int pos1 = 0;
    int pos2 = 0;

    for(int i=0;i<n;i++){
        if(a[i]!=s[i])
            alt1++;
        else{
            if(alt1>mal1){
                pos1 = i;
                mal1 = alt1;
            }
            alt1 = 0;
        }

        if(b[i]!=s[i])
            alt2++;
        else{
            if(alt2>mal2){
                pos2 = i;
                mal2 = alt2;
            }
            alt2 = 0;
        }
    }

    string s1 = s;

    //cout<<mal1<<" "<<mal2<<endl;

    for(int i=mal1;i>0;i--)
        if(s[pos1 - i]=='0')
            s[pos1 - i]='1';
        else
            s[pos1 - i]='0';

    for(int i=mal2;i>0;i--)
        if(s1[pos2 - i]=='0')
            s1[pos2 - i]='1';
        else
            s1[pos2 - i]='0';

    int ans1 = 1;
    int ans2 = 1;

    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])
            ans1++;
        if(s1[i]!=s1[i-1])
            ans2++;
    }

    cout<<max(ans1,ans2);

    return 0;
}