#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	
	cin>>n;
	
	long long arr[n];
	long long arr2[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	sort(arr,arr+n);
	
	for(int i=0,j=0;i<=n/2;i++)
	{
		arr2[j++] = arr[i];
		arr2[j++] = arr[n-1-i];
	}
	
	for(int i=0;i<n;i++)
		cout<<arr2[i]<<" ";
		
	return 0;
}