#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long m,s;
	
	cin>>m>>s;
	
	if(m==1 && s==0)
	{
		cout<<"0 0";
		return 0;
	}
	else if(m>1 && s==0)
	{
		cout<<"-1 -1";
		return 0;
	}
	
	
	long long max[m];
	long long min[m];
	
	long long temp = s;
	
	for(int i=0;i<m;i++)
	{
		if(temp>=9)
		{
			max[i] = 9;
			temp-=9;
		}
		else
		{
			max[i] = temp;
			temp = 0;
		}
	}
	
	if(temp!=0)
	{
		cout<<"-1 -1";
		return 0;
	}
	
	for(int i=0;i<m;i++)
		min[i] = max[m-i-1];
	
	if(min[0]==0)
	{
		min[0] = 1;
		for(int i=1;i<m;i++)
		{
			if(min[i]!=0)
			{
				min[i]--;
				break;
			}
		}
	}
	
	for(int i=0;i<m;i++)
		cout<<min[i];
	
	cout<<" ";
	
	for(int i=0;i<m;i++)
		cout<<max[i];
		
	return 0;
}