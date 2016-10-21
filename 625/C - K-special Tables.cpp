#include<bits/stdc++.h>

using namespace std;

long long arr[505][505];

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N,k;
	
	cin>>N>>k;
	
	long long x = N*N;
	
	long long a = k-1;
	
	for(int i=0;i<N;i++)
	{
		for(int j=N-1;j>=a;j--)
		{
			arr[i][j] = x--;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=a-1;j>=0;j--)
		{
			arr[i][j] = x--;
		}
	}
	
	long long sum = 0;
	
	for(int i=0;i<N;i++)
		sum+=arr[i][k-1];
		
	cout<<sum<<'\n';
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
	
	return 0;
}