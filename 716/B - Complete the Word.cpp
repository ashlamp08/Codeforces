#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	string s;
	cin>>s;
	
	int n = s.size();
	
	if(n<26)
	{
		cout<<-1;
		return 0;
	}
	
	bool flag = false;
	
	for(int i=0;i<=n-26;i++)
	{
		int a[26] = {0};
		int cnt = 0;
		bool poss = true;
		for(int j=0;j<26;j++)
		{
			if(s[i+j]=='?')
			{
				cnt++;
				continue;
			}
			
			if(a[s[i+j]-(int)'A'])
			{
				poss = false;
				break;
			}
			else
			{
				a[s[i+j]-(int)'A']++;
				cnt++;
			}
		}
		
		//cout<<cnt<<endl;
		
		if(!poss)
			continue;
		
		int k=0;
		
		if(cnt==26)	
		{
			for(int j=0;j<26;j++)
			{
				if(s[i+j]=='?')
				{
					while(a[k])
						k++;
					s[i+j] = (char)('A'+k);
					a[k]++;
				}
			}
			
			for(int j=i+26;s[j];j++)
			{
				if(s[j]=='?')
					s[j] = 'A';
			}
			
			for(int j=0;j<i;j++)
			{
				if(s[j]=='?')
					s[j] = 'A';
			}
			
			flag = true;
			break;
		}
	}
	
	if(flag)
		cout<<s;
	else
		cout<<-1;
		
	return 0;
}