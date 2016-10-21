#include<bits/stdc++.h>

using namespace std;

#define ll long long

int c[105];
ll p[105][105];
ll dp[105][105][105];
ll inf = (ll)1e15 + 7;
int M;

ll color(int n,int m,int k)
{
	if(n==-1 && k==0)
		return 0;
	if(k==-1 || n==-1)
		return inf;
	
	if(dp[n][m][k]!=INT64_MAX)
		return dp[n][m][k];
		
	ll res;
	
	if(c[n])
	{
		if(m==c[n])
			dp[n][c[n]][k] = color(n-1,c[n],k);
		else
			dp[n][m][k] = color(n-1,c[n],k-1);
		
		return dp[n][m][k];
	}
		
	for(int i=1;i<=M;i++)
	{
		if(i==m)
			res = p[n][i] + color(n-1,i,k);
		else
			res = p[n][i] + color(n-1,i,k-1);
			
		dp[n][m][k] = min(dp[n][m][k],res);
	}
	
	return dp[n][m][k];
}	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int n,k;
	cin>>n>>M>>k;
	
	for(int i=0;i<n;i++)
		cin>>c[i];
	
	for(int i=0;i<n;i++)
		for(int j=1;j<=M;j++)
			cin>>p[i][j];
			
	for(int i=0;i<=n;i++)
		for(int j=0;j<=M;j++)
			for(int l=0;l<=k;l++)
				dp[i][j][l] = INT64_MAX;
				
	ll ans = INT64_MAX;
	
	if(c[n-1])
		ans = min(ans,color(n-2,c[n-1],k-1));
	else
	{
		for(int i=1;i<=M;i++)
			ans = min(ans,p[n-1][i] + color(n-2,i,k-1));
	}
	
	if(ans>=inf)
		cout<<"-1";
	else
		cout<<ans;
	return 0;
}