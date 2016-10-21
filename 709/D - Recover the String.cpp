#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ll a00,a01,a10,a11;
	
	cin>>a00>>a01>>a10>>a11;
	
	ll zeroes = (1 + round(sqrt(1+8*a00)))/2;
	ll ones = (1 + round(sqrt(1+8*a11)))/2;

	if(a01==0 && a10==0)
	{
		if(a00 == 0)
			zeroes = 0;
		else
			ones = 0;	
	}
	
	if(zeroes*(zeroes-1)!=a00*2 || ones*(ones-1)!=a11*2 || (a01+a10)!=zeroes*ones)
	{
		cout<<"Impossible";
		return 0;
	}
	
	ll length = zeroes+ones;
	
	for(int i=0;i<length;i++)
	{
		if(a01>=ones)
		{
			cout<<0;
			a01-=ones;
			zeroes--;
		}
		else
		{
			cout<<1;
			a10-=zeroes;
			ones--;
		}
	}
	
	return 0;
}