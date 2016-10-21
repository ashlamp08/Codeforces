#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long a[3];
	
	for(int i=0;i<3;i++)
		cin>>a[i];
		
	sort(a, a+3);
	
	long long ans = min((a[0]+a[1]+a[2])/3,a[0]+a[1]);
	
	cout<<ans;
	
	return 0;
}