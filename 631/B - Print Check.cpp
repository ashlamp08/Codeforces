#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n,m,k;
	
	cin>>n>>m>>k;
	
	long long arr[n+5][m+5];
	
	for(int i=0;i<(n+5);i++)
		for(int j=0;j<(m+5);j++)
			arr[i][j]=0;
			
	int q[k][3];
	int r[n+5];
	int c[m+5];
	
	for(int i=0;i<n;i++)
		r[i] = 0;
	for(int j=0;j<m;j++)
		c[j] = 0;
	
	for(int i=0;i<k;i++)
	{
		cin>>q[i][0]>>q[i][1]>>q[i][2];
		q[i][1]--;
	}
		
	for(int i=(k-1);i>=0;i--)
	{
		if(q[i][0]==1)
		{
			if(!r[q[i][1]])
			{
				for(int j=0;j<m;j++)
				{
					if(!arr[q[i][1]][j])
						arr[q[i][1]][j] = q[i][2];
				}
				r[q[i][1]] = 1;
			}
		}
		else
		{
			if(!c[q[i][1]])
			{
				for(int j=0;j<n;j++)
				{
					if(!arr[j][q[i][1]])
						arr[j][q[i][1]] = q[i][2];
				}
				c[q[i][1]] = 1;
			}	
		}
	}
	
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
			cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
	
	return 0;
}