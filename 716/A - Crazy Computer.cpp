#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	ll n,c;
	cin>>n>>c;
	
	ll words = 0;
	
	ll a,b;
	a = 0;
	
	for(int i=0;i<n;i++)
	{
		cin>>b;
		if(b-a>c)
			words = 0;
		a = b;	
		words++;
	}
	
	cout<<words;
	
	return 0;
}