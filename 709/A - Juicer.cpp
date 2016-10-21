#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,b,d;
	
	cin>>n>>b>>d;
	
	long long ans = 0;
	
	long long current = 0;
	
	long long x;
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x<=b)
		{
			current+=x;
			if(current>d)
			{
				ans++;
				current=0;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}