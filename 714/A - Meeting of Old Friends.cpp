#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ll l1,l2,r1,r2,k;
	
	cin>>l1>>r1>>l2>>r2>>k;
	
	ll ans=0;
	
	ll l = max(l1,l2);
	ll r = min(r2,r1);
	
	if(r<l)
		ans = 0;
	else
	{
		ans = r-l+1;
		if(k>=l && k<=r)
			ans--;
	}
	
	cout<<ans;
	
	return 0;
}