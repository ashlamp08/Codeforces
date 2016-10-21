#include<iostream>

using namespace std;

int main()
{
	long long n,ans;
	
	cin>>n;
	
	ans = n/5;
	
	if(n%5)
		ans++;
		
	cout<<ans<<'\n';
	
	return 0;
}