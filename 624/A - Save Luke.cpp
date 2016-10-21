#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long double v1,v2,L,d;
	
	cin>>d>>L>>v1>>v2;
	
	long double ans = (L-d)/(v1+v2);
	
	cout<<setprecision(7)<<fixed;
	cout<<ans;
	
	return 0;
}