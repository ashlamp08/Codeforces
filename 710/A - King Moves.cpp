#include<bits/stdc++.h>

using namespace std;

int main()
{
	char x[3];
	
	cin>>x;
	
	int ans = 8;
	
	if(x[1]=='1' || x[1]=='8')
	{
		ans-=3;
		if(x[0]=='a' || x[0]=='h')
			ans-=2;
	}
	else
	{
		if(x[0]=='a' || x[0]=='h')
			ans-=3;
	}
	
	cout<<ans;
	
	return 0;
}