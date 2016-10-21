#include<bits/stdc++.h>

using namespace std;

bool myfunction (pair<long long, long long> i,pair<long long, long long> j) 
{ 
	if(i.first==j.first)
		return i.second<j.second;
	else
		return i.first<j.first;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin>>n;
	
	pair<long long,long long> p[n];
	
	for(int i=0;i<n;i++)
		cin>>p[i].first>>p[i].second;
		
	sort(p,p+n,myfunction);
	
	long long max = p[0].second;
	
	for(int i=0;i<n;i++)
	{
		if(p[i].second<max)
		{
			if(max<p[i].first)
				max = p[i].first;
		}
		else
			max = p[i].second;
	}
	
	cout<<max;
		
	return 0;
}