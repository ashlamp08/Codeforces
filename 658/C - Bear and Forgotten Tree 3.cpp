#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,d,h;
	
	cin>>n>>d>>h;
	
	if((2*h)<d || (d==1 && h==1 && n>2))
	{
		cout<<-1;
		return 0;
	}
	
	for(int i=1;i<=h;i++)
		cout<<i<<" "<<i+1<<'\n';
	
	if(n>(h+1) && (d>h))
		cout<<1<<" "<<h+2<<'\n';	
	
	for(int i=h+1,j=h+2;i<d;i++,j++)
		cout<<j<<" "<<j+1<<'\n';
	
	for(int i=d+2;i<=n;i++)
		cout<<h<<" "<<i<<'\n';

	return 0;
}