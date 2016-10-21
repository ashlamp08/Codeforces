#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long m,i,j;
	
	cin>>m;
	
	for(i=5,j=0;j<m;i+=5)
	{
		long long x = i;
		while(x%5==0)
		{
			j++;
			x/=5;
		}
	}
	
	i-=5;
	
	
	if(j==m)
	{
		cout<<5<<'\n';
		for(int p=0;p<5;p++,i++)
			cout<<i<<" ";
	}
	else
		cout<<0<<'\n';
		
	return 0;
}