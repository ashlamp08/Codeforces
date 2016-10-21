#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	
	cin>>n>>m;
	
	int ans = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char a;
			cin>>a;
			
			if(a=='C' || a=='M' || a=='Y')
				ans = 1;
		}
	}
	
	if(ans)
		cout<<"#Color";
	else
		cout<<"#Black&White";
		
	return 0;
}