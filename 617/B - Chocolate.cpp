#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,x;
	long long ans = 0;
	int i=0,count = 0;
	
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x)
			break;
	}
	
	if(i<n)
		ans = 1;
		
	i++;
	
	for(;i<n;i++)
	{
		cin>>x;
		if(x)
		{
			ans =ans*(count+1);
			count = 0;
		}
		else
			count++;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}