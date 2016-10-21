#include<bits/stdc++.h>

using namespace std;

long long a[1003];
long long b[1003];
long long am[1003]={0};
long long bm[1003]={0};

long long fa[1003][1003];
long long fb[1003][1003];

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		am[i] = a[i] | am[i-1];

	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		bm[i] = b[i] | bm[i-1];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[i][j] = am[i-1] | am[j];
			fb[i][j] = bm[i-1] | bm[j];
		}
	}
	
	long long maxa = -1;
	long long maxb = -1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(fa[i][j]>maxa)
				maxa = fa[i][j];
	
			if(fb[i][j]>maxb)
				maxb = fb[i][j];
		}
	}
	
	cout<<maxa+maxb;
	
	return 0;
}