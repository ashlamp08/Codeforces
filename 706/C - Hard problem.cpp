#include<bits/stdc++.h>

using namespace std;

string str[(int)1e5+5];
long long c[(int)1e5+5];

long long dp[(int)1e5+5][2];
long long inf =1e14+5 ;

int N;

long long solve(int i,int j)
{
	if(i==N)
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
		
	if(i==0)
		dp[i][j] = min(c[i]+solve(i+1,1),solve(i+1,0));
	else
	{
		string x = str[i-1];
		string y = str[i];
		
		if(j)	
			reverse(x.begin(),x.end());
		
		if(x<=y)
			dp[i][j] = solve(i+1,0);
		else
			dp[i][j] = inf;
	
		reverse(y.begin(),y.end());
		
		if(x<=y)
			dp[i][j] = min(dp[i][j],c[i]+solve(i+1,1));
			
	}
	
	return dp[i][j];
}
			
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	
	cin>>N;
	
	for(int i=0;i<N;i++)
		cin>>c[i];
		
	for(int i=0;i<N;i++)
		cin>>str[i];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<2;j++)
			dp[i][j] = -1;
		
	long long ans = min(solve(0,0),solve(0,1));
	
	if(ans==inf)
		cout<<-1;
	else
		cout<<ans;
	
	return 0;
}