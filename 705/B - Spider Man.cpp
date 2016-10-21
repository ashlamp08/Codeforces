#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin>>N;
	
	long long x;
	long long sum = 0;
	int prev = 2;
	
	for(int i=0;i<N;i++)
	{
		cin>>x;
		sum+=x;
		
		if(prev==2)
		{
			if(sum%2)
				cout<<2<<'\n';
			else
				cout<<1<<'\n';
			prev = 1;
		}
		else
		{
			if(sum%2)
				cout<<1<<'\n';
			else
				cout<<2<<'\n';
			prev = 2;
		}
	}
	
	return 0;
}