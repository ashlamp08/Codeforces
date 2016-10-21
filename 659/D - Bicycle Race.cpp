#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin>>n;
	
	int a1,b1,a2,b2,a3,b3;
	
	cin>>a1>>b1;
	cin>>a2>>b2;
	cin>>a3>>b3;
	
	long long ans = 0;
	
	long long product = (a2-a1)*(b3-b1)-(b2-b1)*(a3-a1);
		
	if(product>0)
		ans++;
	
	for(int i=0;i<n-2;i++)
	{
		a1=a2;
		b1=b2;
		a2=a3;
		b2=b3;
		
		cin>>a3>>b3;

		product = (a2-a1)*(b3-b1)-(b2-b1)*(a3-a1);
		
		if(product>0)
			ans++;
	}
	
	cout<<ans;
	
	return 0;
}