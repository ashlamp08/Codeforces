#include<bits/stdc++.h>

using namespace std;
#define ll long long

long long M = 1e9 + 7;
long long dp[100005];

ll fun(int i)
{
    if (i > 0)
        return dp[i] - dp[i - 1];
    else
        return dp[i];
}

int main()
{
	int t,k;
	cin>>t>>k;
	
	
	dp[0] = 1;
	
	for(int i=1;i<100005;i++)
	{
// 		if(i>=k)
// 		{
// 			dp[i] = (2 + dp[i-1]+dp[i-k])%M;
// 		}
// 		else
// 			dp[i] = (1 + dp[i-1])%M;

        if (i - k >= 0)
            dp[i] = fun(i - 1) + dp[i - 1] + fun(i - k) * 1;
        else
            dp[i] = fun(i - 1) + dp[i - 1];
            
        while (dp[i] < 0)
            dp[i] += M;
        
        dp[i] %= M;
	}
	
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		
		cout<<(dp[b]-dp[a-1]+M)%M<<'\n';
	}
	
	return 0;
}