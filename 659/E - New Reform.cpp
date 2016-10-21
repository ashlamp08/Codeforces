#include<bits/stdc++.h>

using namespace std;

vector<int> graph[100005];
bool visited[100005]={false};
int parent[100005]={0};

int dfs(int u)
{
	visited[u] = true;
	
	int size = graph[u].size();
	int v;
	int cycle=0;
	
	for(int i=0;i<size;i++)
	{
		v = graph[u][i];
		if(!visited[v])
		{
			parent[v] = u;
			cycle = cycle | dfs(v);
		}
		else if(v!=parent[u])
			cycle = 1;
	}
	
	return cycle;
}			
			
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,u,v;
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			ans+= ((dfs(i)+1)%2);
	}
	
	cout<<ans;

	return 0;
}