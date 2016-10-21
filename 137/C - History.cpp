#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
	return a.first<b.first;
}

int main()
{
	int n;
	cin>>n;
	
	pair<int,int> point[n];
	
	for(int i=0;i<n;i++)
		cin>>point[i].first>>point[i].second;
		
	sort(point,point+n,comp);

	int max = -1;
	int count = 0;

	for(int i=0;i<n;i++)
	{
		if(point[i].second<max)
			count++;
		else
			max = point[i].second;
	}
	
	cout<<count;
	
	return 0;
}