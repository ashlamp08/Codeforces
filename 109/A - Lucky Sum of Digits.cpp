#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	
	cin>>n;
	
	long long seven = 0;
	long long four = 0;
	long long m;

	seven = n/7;
	
	for(;seven>=0;seven--)
	{
		m = n - seven*7;
		if(m%4==0)
		{
			four = m/4;
			break;
		}
	}
	
	if(m%4!=0)
		cout<<-1;
	else
	{
		for(int i=0;i<four;i++)
			cout<<4;
		for(int i=0;i<seven;i++)
			cout<<7;
	}
	
	return 0;
}