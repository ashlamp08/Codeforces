#include<bits/stdc++.h>

using namespace std;

long long arr[2003][2003];
long long sumarr[2003][2003];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;

	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	
	long long sum1[2*n];
	long long sum2[2*n];
	
	memset(sum1,0,2*n*sizeof(long long));
	memset(sum2,0,2*n*sizeof(long long));
	memset(sumarr,0,n*n*sizeof(long long));
	
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{	
			sum1[i+j]+=arr[i][j];
			sum2[(n-1-i)+j]+=arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			sumarr[i][j] = sum1[i+j] + sum2[n-1-i+j] - arr[i][j];
		
/*	for(int i=0;i<(2*n-1);i++)
		cout<<sum1[i]<<" ";
		
	cout<<'\n';	
			
	for(int i=0;i<(2*n-1);i++)
		cout<<sum2[i]<<" ";
		
	cout<<'\n';	

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<sumarr[i][j]<<" ";
		}
		cout<<'\n';
	}*/
	
	long long max1=-1, max2=-1;
	int i1,j1,i2,j2;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i&1 && j&1) || (!(i&1) && !(j&1)))
			{
				if(max1<sumarr[i][j])
				{
					max1 = sumarr[i][j];
					i1 = i;
					j1 = j;
				}
			}
			else
			{
				if(max2<sumarr[i][j])
				{
					max2 = sumarr[i][j];
					i2 = i;
					j2 = j;
				}
			}
		}
	}
	
	cout<<max1+max2<<'\n';
	cout<<i1+1<<" "<<j1+1<<" "<<i2+1<<" "<<j2+1;
	
	return 0;
}