#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define M 1000000007

ll dp[102][102][102];

void init()
{
	memset(dp, -1, 102*102*102*sizeof(ll));
}

ll calculate(ll n, ll k, ll d)
{
/*	getchar();
	getchar();
	cout<<n<<" "<<k<<" "<<d<<'\n';*/
	
	if(n<0)
		return 0;
	if(dp[n][k][d]!=-1)
		return dp[n][k][d];
	if(d && n<d)
	{
		dp[n][k][d]=0;
		return 0;
	}
	if(n==0)
	{
		dp[n][k][d]=1;
		return 1;
	}
	
	dp[n][k][d] = 0;
	
	for(int i=1;i<=k;i++)
	{
		if(i>=d)
			dp[n][k][d] = (dp[n][k][d]%M + calculate(n-i,k,0)%M)%M;
		else
			dp[n][k][d] = (dp[n][k][d]%M + calculate(n-i,k,d)%M)%M;
	}
	
	return dp[n][k][d]%M;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	init();
	
	ll n,k,d;
	
	cin>>n>>k>>d;
	
	cout<<calculate(n,k,d);

	return 0;
}