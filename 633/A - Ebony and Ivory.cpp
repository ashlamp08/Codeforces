#include<bits/stdc++.h>

using namespace std;

int dp[1000005] = {0};

bool ans(int a,int b,int c)
{
	if(c<0)
		return 0;
		
	if(c==0)
		return 1;
		
	if(dp[c])
		return dp[c];
	


	//	cout<<"hello";
	dp[c] = (ans(a,b,c-a) || ans(a,b,c-b));
	return dp[c];
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long a,b,c;
	
	cin>>a>>b>>c;
	
	long long x = c/a + 10;
	long long y = c/b + 10;
		
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			if(((i*a+j*b) == c))
			{
				cout<<"Yes";
				return 0;
			}
		}
	}	
	
	cout<<"No";
		
	return 0;
}