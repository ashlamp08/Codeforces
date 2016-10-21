#include<bits/stdc++.h>

using namespace std;

#define MAX 10000007

long long dp[MAX];

int main()
{
	long long n,x,y;
	cin>>n>>x>>y;
	
	for(int i=0;i<MAX;i++)
		dp[i] = (long long)1<<60;

	dp[0] = 0;
	
	for(int i=1;i<MAX;i++)
	{
		dp[i] = min(dp[i],dp[i-1]+x);
		dp[i] = min(dp[i],dp[i+1]+x);
		dp[i] = min(dp[i],(long long)i*x);
		
		if(2*i<MAX)
			dp[2*i] = min(dp[2*i],dp[i]+y);
		
		//cout<<dp[i]<<'\n';
	}
	
	cout<<dp[n];
	
	return 0;
}