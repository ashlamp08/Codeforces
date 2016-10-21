#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int x = n/2;
	int way = 1; 	
			
	int a = 1;
	int b = 2;   		
			
	for(int i=0;i<n;i++)
	{
		if(x==0)
			way=0;
		
		for(int j=0;j<x;j++)
		{
			cout<<b<<' ';
			b+=2;
		}
		for(int j=x;j<(n-x);j++)
		{	
			cout<<a<<' ';
			a+=2;
		}
		for(int j=n-x;j<n;j++)
		{	
			cout<<b<<' ';
			b+=2;
		}
		
		if(way)
			x--;
		else
			x++;
		cout<<'\n';
	}
	
	return 0;
}