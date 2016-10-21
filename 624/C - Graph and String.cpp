#include<bits/stdc++.h>

using namespace std;

long long G[510][510]={0};
int a[510]={0};

int abs(int x)
{
	if(x<0)
		return -x;
	else
		return x;
}


int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M,x,y;

	cin>>N>>M;
	
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		G[x-1][y-1] = 1;
		G[y-1][x-1] = 1;
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==j)
				continue;
			if(G[i][j])
				continue;
			
			if(abs(a[i]-a[j])==2)
				continue;
			
			if(a[i]==0 && a[j]==0)
			{	
				a[i] = 1;
				a[j] = 3;
			}
			else if(a[i]==a[j])
			{
				cout<<"No";
				return 0;
			}
			else if(a[i] == 1)
				a[j] = 3;
			else if(a[i] == 3)
				a[j] = 1;
			else if(a[j] == 1)
				a[i] = 3;
			else if(a[j] == 3)
				a[i] = 1;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		if(!a[i])
			a[i] = 2;
	//	cout<<(char)(a[i]-1+'a');
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(G[i][j] && abs(a[i]-a[j])==2)
			{
				cout<<"No";
				return 0;
			}
			else if(G[i][j]==0 && i!=j)
			{
				if(abs(a[i]-a[j])<=1)
				{
					cout<<"No";
					return 0;
				}
			}
		}
	}
	
	
	cout<<"Yes\n";
	for(int i=0;i<N;i++)
	{
		cout<<(char)(a[i]-1+'a');
	}
	
	return 0;
	
}