#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N;
	cin>>N;
	
	long long arr[N];
	
	for(int i=0;i<N;i++)
		cin>>arr[i];
	
	sort(arr,arr+N);
	
	long long sum = 0;
	
	for(int i=0;i<N;i++)
	{
		sum+=arr[i];
	}
	
	if(sum%2==0)
		cout<<sum<<'\n';
	else
	{
		for(int i=0;i<N;i++)
		{
			if(arr[i]%2)
			{
				sum -= arr[i];
				break;
			}
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}