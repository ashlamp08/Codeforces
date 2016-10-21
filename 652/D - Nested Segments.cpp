#include<bits/stdc++.h>

using namespace std;

struct trip{
	int first;
	int second;
	int third;
};

bool comp1(trip a, trip b)
{
	return a.first<b.first;
}

bool comp2(trip a, trip b)
{
	return a.second<b.second;
}

int bit[400005]={0};

void add(int ind, int val, int N)
{
	while(ind<=N)
	{
		bit[ind]+=val;
		ind += ind & -ind;
	}
}

int fetch(int ind)
{
	int ans = 0;
	while(ind > 0)
	{
		ans += bit[ind];
		ind -= ind & -ind;
	}
	return ans;
}

int main()
{
	int N;
	cin>>N;
	
	trip point[N];
	
	for(int i=0;i<N;i++)
	{
		cin>>point[i].first>>point[i].second;
		point[i].third = i;
	}
		
	int ans[N];
	
	sort(point,point+N,comp2);
	
	for(int i=0;i<N;i++)
		point[i].second = i+1;
		
	sort(point,point+N,comp1);
	
	//~ for(int i=0;i<N;i++)
		//~ cout<<point[i].first<<"  "<<point[i].second<<'\n';
	
	for(int i=N-1;i>=0;i--)
	{
		int val = fetch(point[i].second-1);
		ans[point[i].third] = val;
		add(point[i].second,1,N);
	}
		
	for(int i=0;i<N;i++)
		cout<<ans[i]<<'\n';
		
	return 0;
}