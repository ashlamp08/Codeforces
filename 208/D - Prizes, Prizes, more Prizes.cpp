#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long p[n];
	
	for(int i=0;i<n;i++)
		cin>>p[i];
		
	long long cost[5];
	
	for(int i=0;i<5;i++)
		cin>>cost[i];
	
	long long quant[5]={0};
	
	long long current = 0;
	
	for(int i=0;i<n;i++)
	{
		current+=p[i];
		
		for(int i=4;i>=0;i--)
		{
			if(cost[i]<=current)
			{
				quant[i]+=(current/cost[i]);
				current%=cost[i];
			}
		}
		
	}
	
	for(int i=0;i<5;i++)
		cout<<quant[i]<<" ";
	cout<<'\n'<<current;
	
	return 0;
}