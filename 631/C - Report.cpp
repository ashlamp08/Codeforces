#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m;
	
	cin>>n>>m;
	
	long long arr[n+5];
	long long temp[n+5];
	long long ans[n+5];
	long long stat[n+5];
	long long a[m+5],b[m+5];
	
	for(int i=0;i<n;i++)
		stat[i] = 0;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		temp[i] = arr[i];
	}
		
	long long max = -1;	
		
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
		b[i]--;
	}
	
	for(int i=m-1;i>=0;i--)
	{
		if(b[i]>max)
		{
			for(int j=(max+1);j<=b[i];j++)
				stat[j] = a[i];
			max = b[i];
		}
	}
	
//	for(int i=0;i<n;i++)
//		cout<<stat[i]<<" ";
//	cout<<'\n';
	
	for(int i=(max+1);i<n;i++)
		ans[i] = arr[i];
	
	sort(temp,temp+max+1);
	
	long long x=0,y=max;
	
	for(int i=max;i>=0;i--)
	{
		if(stat[i]==1)
			ans[i] = temp[y--];
		else
			ans[i] = temp[x++];
	}
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
		
	return 0;
}