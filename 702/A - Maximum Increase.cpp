#include<iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	
	int ans = 1;
	int count = 1;
	int x;
	int prev;
	
	cin>>prev;
	N--;
	
	while(N--){
		cin>>x;
		if(x<=prev)
			count = 0;
		
		count++;
		if(count>ans)
			ans = count;
		prev = x;
	}
	
	cout<<ans;
	
	return 0;
}