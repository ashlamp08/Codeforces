#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long a;
	
	cin>>n>>a;
	
	long long arr[n+1];
	long long sumL = 0;
	long long sumR = 0;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<min(abs(arr[0]-a),abs(arr[1]-a));
		return 0;
	}
	
	arr[n] = a;
	
	sort(arr,arr+n+1);
	
	if(arr[0]==a)
	{
		cout<<abs(a-arr[n-1]);
		return 0;
	}
	if(arr[n]==a)
	{
		cout<<abs(a-arr[1]);
		return 0;
	}
	
	sumL = abs(a-arr[0]);
	sumR = abs(a-arr[n]);
	
	long long ans; 
	
	ans = min(sumL-abs(arr[1]-arr[0]) + 2*sumR,sumR-abs(arr[n]-arr[n-1]) + 2*sumL);
	ans = min(ans, (sumR-abs(arr[n]-arr[n-1]))*2 + sumL);
	ans = min(ans, (sumL-abs(arr[0]-arr[1]))*2 + sumR);
	
	cout<<ans;
	
	return 0;
}