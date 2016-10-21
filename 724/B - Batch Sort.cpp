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

int n,m;
int a[21][21];

bool possible(int x, int y)
{
    int b[21][21];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            b[i][j] = a[i][j];

    for(int i=0;i<n;i++)
        swap(b[i][x],b[i][y]);

//    for(int i=0;i<n;i++)
//    {
//
//        for(int j=0;j<m;j++)
//            cout<<b[i][j]<<" ";
//
//        cout<<endl;
//    }

    for(int i=0;i<n;i++)
    {
        int c = 0;
        for(int j=0;j<m;j++)
            if(b[i][j]!=j)
                c++;
        if(c>2)
            return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;


    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j], a[i][j]--;

    if(possible(0,0))
    {
        cout<<"YES";
        return 0;
    }

    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
//            cout<<i+1<<" "<<j+1<<endl;
            if(possible(i,j)){
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";

    return 0;
}