#include<iostream>
#include<algorithm>

using namespace std;

bool comp(pair<int,int> a,pair<int,int> b)
{
	return a.first<b.first;
}

int main()
{
	int N;
	cin>>N;
	
	pair<int,int> arr[102];
	
	for(int i=0;i<N;i++)
	{
		cin>>arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr,arr+N,comp);
	
	for(int i=0;i<N/2;i++)
		cout<<arr[i].second+1<<" "<<arr[N-1-i].second+1<<'\n';
		
	return 0;
}