#include<bits/stdc++.h>

using namespace std;

int m[503];

long long dp[503][503];
long long arr[503][503];
long long ans[503]={0};

void matrix_input(int N)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>arr[i][j];
}

void edge_input(int E, int N)
{
	memset(arr,INT_MAX,(503*503)*sizeof(long long));
	int x,y,w;
	while(E--)
	{
		cin>>x>>y>>w;
		arr[x-1][y-1] = w;
	}
	
	for(int i=0;i<N;i++)
		arr[i][i] = 0;
}
		
void floyd_warshall_mod(int N)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dp[m[i]][m[j]] = arr[i][j];
			
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
		
		for(int i=0;i<=k;i++)
			for(int j=0;j<=k;j++)
				ans[N-k] += dp[i][j];
		
	}				
}

void printshortest(int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<dp[i][j]<<" ";
		cout<<'\n';
	}
}
	
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N,x;
	cin>>N;
	
	matrix_input(N);
	
	for(int i=0;i<N;i++)
	{
		cin>>x;
		m[x-1] = N-1-i;
	}

	floyd_warshall_mod(N);
	
	for(int i=1;i<=N;i++)
		cout<<ans[i]<<" ";
		
	return 0;
}