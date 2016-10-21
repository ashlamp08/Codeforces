#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;

	cin>>n>>m>>k;
	
	pair<int,int> point[n*m+2];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			point[m*i + j].first = i+1;
			point[m*i + j].second = j+1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(i&1)
		reverse(point+m*i, point+m*(i+1));
	}
	
	int temp = m*n;
	int a;
	
/*	for(a=0;a<temp;a++)
	{
		cout<<point[a].first<<" ";
		cout<<point[a].second<<" ";	
	}*/
	

	
	for(a=0;a<temp;a+=2)
	{
		if(a/2==(k-1))
			break;
		else
		{
			cout<<2<<" ";
			cout<<point[a].first<<" ";
			cout<<point[a].second<<" ";
			cout<<point[a+1].first<<" ";
			cout<<point[a+1].second<<"\n";
		}
	}
	
	cout<<(m*n-a)<<" ";
	
	for(;a<temp;a++)
	{
		cout<<point[a].first<<" ";
		cout<<point[a].second<<" ";	
	}
	
	return 0;
}