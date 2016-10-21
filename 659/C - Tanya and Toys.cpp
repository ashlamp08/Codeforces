#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m;
	
	cin>>n>>m;
	
	long long arr[n];
	long long count = 0;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	sort(arr,arr+n);
	
	long long tot=m;
	
	int j=1,k=0;
	
	while(1)
	{
		if(j==arr[k])
			k++;
		else
		{
			tot-=j;
			if(tot<0)
				break;
			count++;
		}
		j++;
	}
	
	cout<<count<<'\n';
	
	tot = m;
	j=1;k=0;
	
	while(1)
	{
		if(j==arr[k])
			k++;
		else
		{
			tot-=j;
			if(tot<0)
				break;
			cout<<j<<' ';
		}
		j++;
	}
		
	return 0;
}