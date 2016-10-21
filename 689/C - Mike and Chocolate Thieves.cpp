#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
	ll m;
	cin>>m;
	
	ll low,high,n;
	
	low = 0;
	high = 10000000000000000L;
	ll ans = -1;
	
	while(low<=high)
	{
		n = (low + high)/2;
		
		ll guess=0;
		ll i = 2;
		ll term = n/(i*i*i);
		
		while(term)
		{
			guess+=term;
			i++;
			term = n/(i*i*i);
		}
		
		//cout<<low<<"\t"<<n<<'\t'<<high<<'\t'<<guess<<'\n';
		
		if(guess==m)
			ans = n;
		
		if(guess<m)
			low = n+1;
		else
			high = n-1;
	}
			
	cout<<ans;
		
	return 0;
}