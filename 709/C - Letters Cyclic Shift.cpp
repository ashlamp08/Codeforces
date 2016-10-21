#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	
	cin>>s;
	
	int n = s.size();
	
	int i = 0;
	
	for(i=0;i<n;i++)
	{
		if(s[i]!='a')
			break;
		//cout<<s[i];
	}
	
	if(i==n)
		s[n-1] = 'z';
	
	for(;i<n;i++)
	{
		if(s[i]!='a')
			s[i]--;
		else
			break;
		//cout<<s[i];
	}
	
	cout<<s;
	
	return 0;
}