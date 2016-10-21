#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main()
{
	int n,t;
	cin>>n>>t;
	
	char s[n+5];
	cin>>s;
	
	int point = 0;

	while(s[point] && s[point]!='.')point++;
	
	if(point==n)
	{
		cout<<s;
		return 0;
	}
	
	if(point==0)
	{
		for(int i=n;i>0;i--)
			s[i]=s[i-1];
		s[n+1]='\0';
		s[0]='0';
		point = 1;
	}
	
	int i=point+1;
	
	bool flag = false;
	
	
		while(s[i] && s[i]<'5')
			i++;
		if((int)s[i])
		{	
		s[i] = '\0';
		i--;
	
		while(i>=0)
		{
			if(s[i]=='.')
			{
				i--;
				flag = true;
				continue;
			}
			
			if(flag&&s[i]=='9')
			{
				s[i] = '0';
				i--;
				while(i>=0 && s[i]=='9')
				{	
					s[i] ='0';
					i--;
				}
				if(i<0)
					cout<<'1';
				else
					s[i]++;
			}
			else
			{
				//cout<<"i  "<<i<<endl;
				s[i]++;
				i--;
			}
			t--;
			if(!t)
				break;
			
			if(flag)
				break;
			if(s[i+1]<'5')
					break;
		}	
		
	}
	
	if(flag)
	{	
		s[point]='\0';
		cout<<s;
	}
	else
	{
		s[i+2]='\0';
		if(s[0]=='0')
		{
			for(int i=0;s[i];i++)
				cout<<s[i];
		}
		else
			cout<<s;
	}
	
	return 0;
}