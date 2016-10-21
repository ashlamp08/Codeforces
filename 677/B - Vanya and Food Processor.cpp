#include<iostream>

using namespace std;

int main()
{
	long long n,h,k;
	
	cin>>n>>h>>k;
	
	long long a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	long long current = 0;
	long long ans = 0;
	
	for(int i=0;i<n;i++)
	{
		if(current+a[i]>h)
		{
			ans+=current/k;
			current = current%k;
			
			if(current+a[i]>h)
			{
				current = 0;
				ans++;
			}
		}
		
		current+=a[i];
		
		//cout<<current<<'\n';
	}
	ans+=current/k;
	if(current%k)
		ans++;
	
	cout<<ans<<'\n';
	
	return 0;
}