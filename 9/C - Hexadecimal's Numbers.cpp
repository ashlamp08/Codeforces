#include<bits/stdc++.h>

using namespace std;

long long calculate(long long n)
{
	long long ans = 0;
	int i=0;
	
	while(n)
	{
		if(n%10)
			ans+=(long long)(pow(2,i));
		n/=10;
		i++;
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char n[20];
	
	cin>>n;
	
	int l = strlen(n);
	int i=0;
	
	for(i=0;i<l;i++)
	{
		if(n[i]>'1')
		{
			n[i++] = '1';
			break;
		}
	}
	
	for(;i<l;i++)
		n[i] = '1';
		
	long long num = atoi(n);
	
	cout<<calculate(num);
	

	return 0;
}