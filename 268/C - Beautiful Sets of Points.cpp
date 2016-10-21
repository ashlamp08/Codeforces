#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,k;
	
	cin>>n>>k;
	
	cout<<min(n,k)+1<<'\n';
	
	long long x = min(n,k);
	
	for(int i=0;i<=x;i++)
		cout<<i<<" "<<x-i<<'\n';
		
	return 0;
}