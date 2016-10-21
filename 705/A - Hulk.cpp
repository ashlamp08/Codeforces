#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin>>N;
	
	cout<<"I hate";
	
	for(int i=1;i<N;i++)
	{
		if(i%2)
			cout<<" that I love";
		else 
			cout<<" that I hate";
	}
	
	cout<<" it";

	return 0;
}