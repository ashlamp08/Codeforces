#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long h1,h2,a,b,day=0;
	
	cin>>h1>>h2>>a>>b;
	
	h1 += a*8;
	
	if(h1 >= h2)
	{
		cout<<0;
		return 0;
	}
	
	if(b>=a)
	{
		cout<<-1;
		return 0;
	}
	
	while(h1<h2)
	{
		h1-= 12*b;
		h1+= 12*a;
		day++;
	}
	
	cout<<day;
	
	return 0;

}