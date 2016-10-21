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

int n,m,b;
ll mod;
int a[505];

int dp[2][501][501]={0};

int solve(int i,int j,int k){
    if(i<0 || j<0 || k<0)
        return 0;

    if(dp[i][j][k]!=-1)
        return dp[i][j][k];

    if(i==0 && j==0 && k>=0)
        return 1;

    return dp[i][j][k] = (solve(i,j-1,k - a[i]) + solve(i-1,j,k))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m>>b>>mod;

    for(int i=0;i<n;i++)
        cin>>a[i+1];

    dp[0][0][0] = dp[1][0][0] = 1;

    int curr = 1;
    int prev = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=b;k++)
            {
                if(k>=a[i])
                    dp[curr][j][k] = (dp[curr][j-1][k-a[i]] + dp[prev][j][k])%mod;
                else
                    dp[curr][j][k] = dp[prev][j][k];
            }
        }
        prev = !prev;
        curr = !curr;
    }

    ll ans = 0;

    for(int k=0;k<=b;k++)
        ans = (ans + dp[prev][m][k])%mod;

    cout<<ans;

    return 0;
}