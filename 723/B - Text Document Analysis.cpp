#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int n;
	cin>>n;
	
	string S;
	cin>>S;
	
	int c1 = 0;
	int c2 = 0;
	
	bool in = false;
	
	for(int i=0;S[i];i++)
	{
		if(S[i]=='(')
		{
			in = true;
			i++;
		}
		
		if(in)
		{
			while(in)
			{
				while(S[i]=='_' && i<n)
				 i++;
			
				if(S[i]==')' || S[i]=='\0')
				{
					in = false;
					break;
				}
				
				if(in)
				{
					int j = i;
					while(((S[i]>='a' && S[i]<='z')  || (S[i]>='A' && S[i]<='Z')) && (i<n))
					{
						//cout<<S[i];
						i++;
					}
						
					if(i-j>=1)
						c2++;
				}
			
				if(S[i]==')')
				{
					in = false;
					break;
				}
				
				//cout<<S[i];
			}
			
			in = false;
		}
		else
		{			
			while(!in)
			{
				while(S[i]=='_' && i<n)
				i++;
				
				
				if(S[i]=='(' || S[i]=='\0')
				{
					in = true;
					break;
				}
				
				if(!in)
				{
					int cc =0;
					while(((S[i]>='a' && S[i]<='z')  || (S[i]>='A' && S[i]<='Z'))  && i<n)
					{	
						i++;
						cc++;
					}
					
					c1 = max(c1,cc);
				}
				
				if(in || S[i]=='\0')
					break;
			}
		}
		
		if(!S[i])
			break;
	}
	
	cout<<c1<<" "<<c2<<'\n';
	
	return 0;
}