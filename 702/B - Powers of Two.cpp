#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	
	long long arr[N];
	
	map<long long, long long> m;
	
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		m[arr[i]]++;
	}
	
	long long two_power[33];
	
	two_power[0] = 1;
	
	for(int i=1;i<33;i++)
		two_power[i] = two_power[i-1]<<1;

	long long ans = 0;
	
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<33;j++)
		{
			long long x =(two_power[j]-arr[i]);
			if(x>0 && x!=arr[i])
				ans+=m[x];
			else if(x>0 && x==arr[i])
				ans+=(m[x]-1);
		}
	}
	
	cout<<ans/2;
	
	return 0;
}