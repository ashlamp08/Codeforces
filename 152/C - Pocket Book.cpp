#include<bits/stdc++.h>

using namespace std;

#define M 1000000007

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m,ans=1,count;

	cin>>n>>m;
	
	int flag[26] = {0};
	
	char arr[n][m+1];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	for(int i=0;i<m;i++)
	{
		memset(flag,0,26*sizeof(int));
		count = 0;
		for(int j=0;j<n;j++)
			flag[(int)(arr[j][i]-'A')] = 1;
		for(int j=0;j<26;j++)
		{
			if(flag[j])
				count++;
		}
		ans = (ans * count)%M;
	}
	
	cout<<ans%M;
	
	return 0;
}