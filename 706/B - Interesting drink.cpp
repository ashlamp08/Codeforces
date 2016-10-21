#include<bits/stdc++.h>

using namespace std;

long long x[(int)1e5+5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>x[i];
		
	sort(x,x+n);
	
	int q;
	cin>>q;
	
	long long m;
	
	while(q--)
	{
		cin>>m;
		if(m<x[0])
			cout<<0<<'\n';
		else
			cout<<upper_bound(x,x+n,m)-x<<'\n';
	}
	
	return 0;
}