#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, a;
	long long ans = 0;
	priority_queue<int> Q;
	cin>>n>>a;
	Q.push(a);
	for(int i=1; i<n; i++)
	{
		cin>>a; a-=i;
		Q.push(a);
		
		
		if(Q.top() > a)
		{
			ans += Q.top() - a;
			Q.pop();
			Q.push(a);
		}
	}
	cout<<ans;
	return 0;
}