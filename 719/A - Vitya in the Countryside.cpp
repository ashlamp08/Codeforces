#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main()
{
	int n;
	cin>>n;
	
	int a=-1,b;
	
	for(int i=0;i<n;i++)
	{	
		if(i)
			b = a;
		cin>>a;
	}
	
	if(n==1 && a!=15 && a!=0)
		cout<<"-1";
	else if(a==15)
		cout<<"DOWN";
	else if(a==0)
		cout<<"UP";
	else
	{
		if(b<a)
			cout<<"UP";
		else
			cout<<"DOWN";
	}
	
	return 0;
}