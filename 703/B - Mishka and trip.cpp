#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N,k;
	cin>>N>>k;
	
	long long arr[N+1];
	int c[N+1];
	
	long long sum = 0;
	
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		c[i] = 0;
	}
	
	for(int i=0,x;i<k;i++)
	{	
		cin>>x;
		x--;
		c[x] = 1;
	}
	
	long long ans = 0;
	
	for(int i=0;i<N;i++)
	{
		if(!c[i] && !c[(i+1)%N])
			ans+=(arr[i]*arr[(i+1)%N]);
		if(c[i])
		{
			ans+=((sum-arr[i])*arr[i]);
			sum-=arr[i];
		}
			
	}
	
	cout<<ans;
	
	return 0;
}