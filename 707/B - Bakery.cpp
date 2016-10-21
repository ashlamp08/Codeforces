#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,k;
	
	cin>>n>>m>>k;
	
	int edges[m][3];
	int shop[n+1];
	
	for(int i=0;i<m;i++)
		cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
		
	for(int i=0;i<=n;i++)
		shop[i] = 0;
		
	for(int i=0;i<k;i++)
	{
		int a;
		cin>>a;
		shop[a] = 1;
	}
	
	int ans = INT_MAX;
	
	for(int i=0;i<m;i++)
	{
		if((shop[edges[i][0]] && !shop[edges[i][1]]) || (!shop[edges[i][0]] && shop[edges[i][1]]))
			ans = min(ans,edges[i][2]);
	}
	
	if(ans==INT_MAX || k==0)
		cout<<-1;
	else
		cout<<ans;
		
	return 0;
}