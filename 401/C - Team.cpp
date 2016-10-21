#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m;
	
	cin>>n>>m;
	
	if(m<(n-1))
	{
		cout<<-1;
		return 0;
	}
	
	if(m>(2*(n+1)))
	{
		cout<<-1;
		return 0;
	}

	if(m<=n)
	{
		for(int i=0;i<m;i++)
			cout<<"01";
		if(m<n)
			cout<<'0';
		return 0;
	}

	long long a[2] = {0};
	long long temp = m;	
		
	for(int i=0;i<2;i++)
	{
		if(temp >= (n+1))
		{
			a[i] = n+1;
			temp-=(n+1);
		}
		else
		{
			a[i] = temp;
			temp = 0;
		}
	}
	
//	cout<<a[0]<<"  "<<a[1]<<"  "<<'\n';
	

	for(int i=0;i<(a[1]-1);i++)
		cout<<"110";
	if(a[1]>0 && a[1]<(n+1))
		cout<<"110";
	else if(a[1]>0 && a[1]==(n+1))
		cout<<"11";
	
	if(a[1]!=(n+1))
	{
		
	for(int i=a[1];i<(a[0]-1);i++)
		cout<<"10";
	if(a[0]>0 && a[0]<(n+1))
		cout<<"10";
	else if(a[0]>0 && a[0]==(n+1))
		cout<<"1";
	}
	
	return 0;
}