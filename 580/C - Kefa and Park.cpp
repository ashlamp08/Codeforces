#include<bits/stdc++.h>

using namespace std;

int cat[100005];
int par[100005];
int visited[100005];
int concat[100005];
int maxcat[100005];
vector<int> tree[100005];

int dfs(int m)
{
	stack<int> s;
	visited[0] = 1;
	concat[0] = cat[0];
	
	int count =0;
	s.push(0);
	
	while(!s.empty())
	{
		int u = s.top();
		s.pop();
		
		int n = tree[u].size();
		
		for(int i=0;i<n;i++)
		{
			int v = tree[u][i];
			
			if(!visited[v])
			{
				par[v] = u;
				visited[v] = 1;
				s.push(v);
				
				if(cat[v] && cat[par[v]])
					concat[v] = concat[par[v]]+1;
				else if(cat[v])
					concat[v] = 1;
					
				maxcat[v] = max(concat[v],maxcat[par[v]]); 
			}
		}
		
		if(n==1 && tree[u][0]==par[u])
		{
			if(maxcat[u]<=m)
				count++;
		}
	}
	
	return count;
}


int main()
{
	int n,m;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>cat[i];
		
	for(int i=0;i<n;i++)
	{
		par[i] = -1;
		visited[i] = concat[i] = maxcat[i] = 0;
	}
	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		
		a--;b--;
		
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	cout<<dfs(m);
	
	return 0;
}