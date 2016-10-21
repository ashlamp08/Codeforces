#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int n;
	cin>>n;
	
	ll a;
	set<ll> S;
	
	for(int i=0;i<n;i++)
		cin>>a, S.insert(a);
		
	while(1)
	{
		ll mx = *(--S.end());
		ll e = mx/2; 
		
		while(e>0 && S.find(e)!=S.end())
			e/=2;
		
		if(!e)
			break;
		
		S.erase(mx);
		S.insert(e);
	}
	
	for(auto x: S)
		cout<<x<<" ";
		
	return 0;
}