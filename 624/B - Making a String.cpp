#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	
	cin>>n;
	
	long long a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	sort(a,a+n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>=1;j--)
		{
			if(a[j-1]>=a[j])
			{
				if(a[j]==0)
					a[j-1] = 0;
				else
					a[j-1] = a[j] - 1;
			}
		}
	}
	
	long long sum=0;
	
	for(int i=0;i<n;i++)
		sum+=a[i];
		
	cout<<sum;
	
	return 0;
}