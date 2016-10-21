#include<bits/stdc++.h>

using namespace std;

int board[1003][1003] = {0};

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N;
	cin>>N;
	
	int x,y;
	
	for(int i=0;i<N;i++)
	{
		cin>>x>>y;
		board[x-1][y-1] = 1;
	}
	
	long long sum = 0;
	
	for(int i=0;i<1000;i++)
	{
		int count = 0;
		for(int j=0,k=i;j<1000 && k<1000;j++,k++)
		{
			if(board[k][j])
				count++;
		}
		sum+=(count*(count-1)/2);
	}
	
	for(int i=1;i<1000;i++)
	{
		int count = 0;
		for(int j=0,k=i;j<1000 && k<1000;j++,k++)
		{
			if(board[j][k])
				count++;
		}
		sum+=(count*(count-1)/2);
	}
	
	for(int i=1000-1;i>=0;i--)
	{
		int count = 0;
		for(int j=0,k=i;j<1000 && k>=0;j++,k--)
		{
			if(board[k][j])
				count++;
		}
		sum+=(count*(count-1)/2);
	}
	
	for(int i=1;i<1000-1;i++)
	{
		int count = 0;
		for(int j=1000-1,k=i;j>=0 && k<1000;j--,k++)
		{
			if(board[j][k])
				count++;
		}
		sum+=(count*(count-1)/2);
	}
		
	cout<<sum<<'\n';
	
	return 0;
}