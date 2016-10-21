#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int p[n];
	
	for(int i=0;i<n;i++)
		cin>>p[i];
		
	bool flag = true;	
		
	cin.get();	
	for(int i=0;i<n;i++)
	{	
		char s[105];
		cin.getline(s,sizeof(s));
		
		//cout<<s<<endl;
	
		int c=0;
	
		for(int j=0;s[j];j++)
		{
			if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='y')
				c++;
		}
		
		if(c!=p[i])
			flag = false;
	}
	
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
		
	return 0;
}