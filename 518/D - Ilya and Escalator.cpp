#include<bits/stdc++.h>

using namespace std;

double dp[2004][2004];

double solve(int n,double p, int t)
{
	//cout<<n<<"  "<<t<<endl;
	
	if(dp[n][t]!=-1)
		return dp[n][t];	
	
	if(n==0)
		return dp[n][t] = (1.0-p)*solve(n,p,t-1);
		
	if(t==0)
		return 0;
	
	dp[n][t] = p*(solve(n-1,p,t-1)+1) + (1.0-p)*solve(n,p,t-1);
	
	return dp[n][t];
}

int main()
{
	int n,t;
	double p;
	
	cin>>n>>p>>t;
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=t;j++)
			dp[i][j] = -1;
			
	double ans = solve(n,p,t);
	
	dp[0][0] = 0.0;
	
	printf("%.12lf",ans);
}