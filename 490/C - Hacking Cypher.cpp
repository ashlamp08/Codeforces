#include<bits/stdc++.h>

using namespace std;

char a[1000006];
long long remb[1000006];
long long remc[1000006];

bool isZero(int begin,int end)
{
	for(int i=begin;i<end;i++)
	{	
		if(a[i]!='0')
			return false;
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long b,c;
	
	cin>>a>>b>>c;
		
	long long n = strlen(a);
	
	remb[0] = ((long long)(a[0]-'0'))%b;
	remc[n-1] = ((long long)(a[n-1]-'0'))%c;
	//cout<<remb[0];
	
	for(int i=1;i<(n-1);i++)
	{
		remb[i] = (((remb[i-1]*10)%b) + ((int)(a[i]-'0'))%b)%b;
//		cout<<remb[i]<<" ";
	
	}
//	cout<<'\n';
	for(int i=n-2,P=10;i>0;i--,P*=10)
	{
		P = P%c;
		remc[i] = ((((int)(a[i]-'0'))*P)%c +  remc[i+1]%c)%c;
//		cout<<remc[i]<<" ";
	
	}
//	cout<<'\n';
	
		
	for(int i=0;i<(n-1);i++)
	{
		if(isZero(i+1,n))
			break;
			
		if(a[i+1]=='0')
		{
			continue;	
		}
		
		if(!(remb[i]) && !remc[i+1])
		{
			cout<<"YES\n";
			
			for(int j=0;j<=i;j++)
				cout<<a[j];
			
			cout<<"\n";
			
			for(int j=i+1;j<n;j++)
				cout<<a[j];
			
			return 0;
		}
	}

	cout<<"NO";
		
	return 0;
}