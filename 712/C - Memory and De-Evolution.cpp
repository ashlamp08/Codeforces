#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	int x,y;
	
	cin>>x>>y;
	
	int a[3];
	
	a[0] = a[1] = a[2] = y;
	
	bool flag = true;
	
	int ans = 0;
	
	while(flag)
	{
		sort(a,a+3);
		
		a[0] = a[1]+a[2]-1;
		
		a[0] = min(a[0],x);
		
		ans++;
		
		if(a[0]==x && a[1]==x && a[2]==x)
			flag = false;
	}
	
	cout<<ans;
	
	return 0;
}