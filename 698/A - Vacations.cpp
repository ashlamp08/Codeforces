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

int dp[105][3];
int a[105];

int solve(int i, int j){

    if(i<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(a[i]==0)
        return dp[i][j] = 1 + solve(i-1,0);

    if(j == 0){
        if(a[i]==1)
            return dp[i][j] = min(solve(i-1,1),1+solve(i-1,0));
        if(a[i]==2)
            return dp[i][j] = min(solve(i-1,2),1+solve(i-1,0));
        if(a[i]==3)
            return dp[i][j] = min(min(solve(i-1,1),solve(i-1,2)),1+solve(i-1,0));
    }
    if(j == 1){
        if(a[i]==1)
            return dp[i][j] = 1+solve(i-1,0);
        if(a[i]==2 || a[i]==3)
            return dp[i][j] = min(solve(i-1,2),1+solve(i-1,0));
    }
    if(j == 2){
        if(a[i]==2)
            return dp[i][j] = 1+solve(i-1,0);
        if(a[i]==1 || a[i]==3)
            return dp[i][j] = min(solve(i-1,1),1+solve(i-1,0));
    }

    return dp[i][j];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            dp[i][j] = -1;
    }

    cout<<solve(n-1,0);



    return 0;
}