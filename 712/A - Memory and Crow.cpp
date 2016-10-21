#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	int n;
	cin>>n;
	
	ll a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	for(int i=0;i<n-1;i++)
		cout<<a[i]+a[i+1]<<" ";
		
	cout<<a[n-1];
	
	return 0;
}