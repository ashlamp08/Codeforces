#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	int n;
	cin>>n;
	
	set<ll> S;
	
	for(int i=0;i<n;i++)
	{	
		int x;
		cin>>x;
		S.insert(x);
	}
	
	int sz = S.size();
	
	if(sz>3)
		cout<<"NO";
	else if(sz<=2)
		cout<<"YES";
	else
	{
		int i=0;
		ll arr[3];
		for(auto a: S)
			arr[i++] = a;
			
		sort(arr,arr+3);
		
		if(arr[1]-arr[0] == arr[2]-arr[1])
			cout<<"YES";
		else
			cout<<"NO";
	}
	
	return 0;
}