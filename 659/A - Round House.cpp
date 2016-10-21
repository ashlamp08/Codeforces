#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a,b,n,ans;
	
	cin>>n>>a>>b;
	
	ans = (a+b+n*100)%n;
	
	if(ans==0)
		cout<<n;
	else
		cout<<ans;
		
	return 0;
}