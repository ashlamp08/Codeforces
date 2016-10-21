#include<iostream>
#include<algorithm>

using namespace std;

long long fre[100005] = {0};
long long dp[100005];

long long max(long long a, long long b)
{
	if(a>b)
		return a;
	else
		return b;
}

long long del(long long i)
{
	if(i>100004)
		return 0;
	if(dp[i]!=-1)
		return dp[i];	
	if(fre[i]==0)
	{
		dp[i] = del(i+1);
		return dp[i];
	}
	else
	{
		dp[i] = max(fre[i]+del(i+2),del(i+1));
		return dp[i];
	}
}
		
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0;i<100005;i++)
		dp[i] = -1;
	
	long long n;
	cin>>n;
	
	long long x;
	
	for(long long i=0;i<n;i++)
	{
			cin>>x;
			fre[x]+=x;
	}
	
	long long ans = del(0);
	
	cout<<ans<<'\n';
	
	return 0;
}