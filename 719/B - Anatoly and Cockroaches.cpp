#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main()
{
	int n;
	cin>>n;
	
	string s;
	
	cin>>s;
	
	int c1r = 0;
	int c2r = 0;
	int c1b = 0;
	int c2b = 0;
	
	for(int i=0;i<n;i++)
	{
		if(i%2)
		{
			if(s[i]=='r')
				c1r++;
			if(s[i]=='b')
				c2b++;
		}
		else
		{
			if(s[i]=='b')
				c1b++;
			if(s[i]=='r')
				c2r++;
		}
	}
	
	if(c1r+c1b<c2r+c2b)
	{
		int x = min(c1r,c1b);
		c1r-=x;
		c1b-=x;
		cout<<x+c1r+c1b;
	}
	else
	{
		int x = min(c2r,c2b);
		c2r-=x;
		c2b-=x;
		cout<<x+c2r+c2b;
	}
	
	return 0;
}