#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> e[200005];
int ans[200005]={0};
int visited[200005]={0};

void bfs()
{
	visited[0] = 1;
	ans[0]= 0;
	
	queue<int> Q;
	Q.push(0);
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		for(auto v:e[u])
		{
			//cout<<v<<'\n';
			if(!visited[v])
			{
				Q.push(v);
				visited[v] = 1;
				ans[v] = ans[u]+1;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{	
		e[i].push_back(i+1);
		e[i+1].push_back(i);
	}
	
	for(int i=0;i<n;i++)
	{	
		cin>>arr[i];
		arr[i]--;
		
		e[i].push_back(arr[i]);
	}
	
	bfs();
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
		
	return 0;
}