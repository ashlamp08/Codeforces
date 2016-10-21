#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin>>N;
	
	int M=0,C=0;
	
	int a,b;
	
	for(int i=0;i<N;i++)
	{
		cin>>a>>b;
		
		if(a>b)
			M++;
		else if(b>a)
			C++;
	}

	if(M>C)
		cout<<"Mishka";
	else if(C>M)
		cout<<"Chris";
	else
		cout<<"Friendship is magic!^^";
		
	return 0;
}