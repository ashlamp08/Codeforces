#include<bits/stdc++.h>

using namespace std;

struct trip{
	int first;
	int second;
	int third;
};

bool comp(trip a, trip b){
	return (a.second==b.second)?a.first<b.first:a.second>b.second;
}

bool comp1(trip a, trip b){
	return a.third<b.third;
}

int main()
{
	int n,m;
	
	cin>>n>>m;
	
	trip weight[m];
	pair<int,int> orig_edges[m];
	vector<int> graph[n];
	
	for(int i=0;i<m;i++)
	{
		cin>>weight[i].first>>weight[i].second;
		weight[i].third = i;
	}
		
	sort(weight, weight + m, comp);			
		
	for(int i=0;i<(n-1);i++)
		orig_edges[i] = make_pair(i+1,i+2);
	
	int current_node = 2;
	int pointed = 0;
	bool failed = false;
	
	for(int i=n-1;i<m;i++)
	{
		if(pointed == current_node-1)
		{
			current_node++;
			pointed=0;
		}
		
		if(current_node!=n && (weight[i].first >= weight[current_node-1].first))
		{
			orig_edges[i] = make_pair(current_node+1,pointed+1);
			pointed++;
		}
		else
		{
			//cout<<weight[i].first<<"   "<<weight[current_node-1].first;
			failed = true;
			break;
		}
	}
	
	if(failed)
	{	
		cout<<-1;
		return 0;
	}
	
	for(int i=0;i<m;i++)
	{	
		weight[i].first = orig_edges[i].first;
		weight[i].second = orig_edges[i].second;
	}
	
	sort(weight,weight+m,comp1);
	
	for(int i=0;i<m;i++)
		cout<<weight[i].first<<" "<<weight[i].second<<'\n';
	
				
		
	return 0;
}


/*
4 5
2 1
3 1
4 0
1 1
5 0

5 7
5 1
5 1
6 1
7 1
5 0
6 0
4 0

3 3
4 1
5 0
7 1

*/