#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	ll a[3];
	
	cin>>a[0]>>a[1]>>a[2];
	
	sort(a,a+3);
	
	cout<<a[2]-a[0];
	
	return 0;
}