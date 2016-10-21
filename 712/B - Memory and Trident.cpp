#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	string s;
	cin>>s;
	
	if(s.size()&1)
	{
		cout<<"-1";
		return 0;
	}
	
	int l=0,r=0,u=0,d=0;
	
	for(int i=0;s[i];i++)
	{
		if(s[i]=='L')
			l++;
		else if(s[i]=='R')
			r++;
		else if(s[i]=='U')
			u++;
		else if(s[i]=='D')
			d++;
	}
	
	int lr = min(l,r);
	int ud = min(u,d);
	
	int ans = 0;
	
	l-=lr;
	r-=lr;
	u-=ud;
	d-=ud;
	
	ans = l+r+u+d;
	ans/=2;
	
	cout<<ans;
	
	return 0;
}