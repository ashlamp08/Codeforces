#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	long long n,m;
	
	cin>>n>>m;
	
	int row[100005]={0},col[100005]={0};
	int r=n,c=n;
	
	long long ans = n*n;
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		
		if(!row[a])
		{
			row[a]=1;
			ans-=c;
			r--;
		}
		if(!col[b])
		{
			col[b]=1;
			ans-=r;
			c--;
		}
		cout<<ans<<" ";
	}
	
	return 0;
}