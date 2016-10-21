#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	
	cin>>n>>m;
	
	long long arr[m];
	
	for(int i=0;i<m;i++)
		cin>>arr[i];
		
	sort(arr,arr+m);
	
	long long min = 999999999999;
	
	for(int i=0;i<(m-n+1);i++)
	{
		if(arr[i+n-1]-arr[i] < min)
			min = arr[i+n-1]-arr[i];
	}
	
	cout<<min<<'\n';
	
	return 0;
}