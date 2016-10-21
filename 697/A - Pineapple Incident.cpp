#include<iostream>

using namespace std;

int main()
{
	int t,s,x;
	
	cin>>t>>s>>x;
	
	x-=t;
	
	if(x<0)
		cout<<"NO";
	else
		if(x%s==0 || ((x>1) && (x-1)%s==0))
			cout<<"YES";
		else 
			cout<<"NO";
			
			
	return 0;
}