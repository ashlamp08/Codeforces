#include<bits/stdc++.h>

using namespace std;

bool compfnx(pair<long long, long long> a, pair<long long, long long> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

bool compfny(pair<long long, long long> a, pair<long long, long long> b)
{
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	
	cin>>n;
	
	pair<long long,long long> point[n];
	
	for(int i=0;i<n;i++)
		cin>>point[i].first>>point[i].second;
	
	long long ans = 0;
	long long count = 1;
	
	sort(point,point+n,compfnx);
	
	for(int i=1;i<n;i++)
	{
		if(point[i].first == point[i-1].first)
			count++;
		else
		{
			ans+= ((count-1)*count/2);
			count = 1;
		}
	}
	
	sort(point,point+n,compfny);
	
	ans+= ((count-1)*count/2);
	count = 1;
	
	for(int i=1;i<n;i++)
	{
		if(point[i].second == point[i-1].second)
			count++;
		else
		{
			ans+= ((count-1)*count/2);
			count = 1;
		}
	}
	
	ans+= ((count-1)*count/2);
	count = 1;
	
	for(int i=1;i<n;i++)
	{
		if(point[i].second == point[i-1].second  && point[i].first == point[i-1].first)
			count++;
		else
		{
			ans-= ((count-1)*count/2);
			count = 1;
		}
	}
	ans-= ((count-1)*count/2);
	
	cout<<ans;
	
	return 0;
}