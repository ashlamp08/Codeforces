#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin>>n;
	
	long long arr[n];
	
	long long sum = 0;
	
	for(int i=0;i<n;i++)
	{	
		cin>>arr[i];
		sum+=arr[i];
	}
	
	if(sum%3!=0)
	{
		cout<<0;
		return 0;
	}
	
	long long count[n];
	long long tempSum = 0;
	long long tempCount = 0;
	long long ans = 0;
	
	count[n-1] = 0; 
	
	for(int i=n-1;i>=0;i--)
	{
		tempSum+=arr[i];
		if(tempSum==(sum/3))
			tempCount++;
			
		count[i] = tempCount;
	}
	
//	for(int i=0;i<n;i++)
//		cout<<count[i]<<" ";
	
	tempSum = 0;
	
	for(int i=0;i<(n-2);i++)
	{
		tempSum+=arr[i];
		
		if(tempSum==(sum/3))
			ans+=count[i+2];
	}
	
	cout<<ans;
				
	
	return 0;
}