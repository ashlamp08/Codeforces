#include<bits/stdc++.h>

using namespace std;

vector<int> e[400005];
int subtree[400005];
int ans[400005];
int n;

int dfs(int u, int p)
{
	subtree[u] = 1;
	
	for(auto v: e[u])
	{
		if(v!=p)
			subtree[u]+=dfs(v,u); 
	}
	return subtree[u];
}

void check(int x, int p, int maxim)
{
	if(subtree[x]+maxim>=(n-n/2))
		ans[x] = 1;
	else
		ans[x] = 0;
	for(auto u: e[x])
	{
		if(u!=p)
			check(u,x,maxim);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b; 
		a--;
		b--;
		
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	dfs(0,-1);		//storing number of subtrees at each node if 0 is root
	
	//find a valid centroid
	
	int centroid = 0;
	int parent = -1;
	bool found = true;
	
	while(found)
	{
		found = false;
		for(auto v: e[centroid])
		{
			if(subtree[v]>n/2 && v!=parent)
			{
				parent = centroid;
				centroid = v;
				found = true;
				break;
			}
		}
	}
	
	// calculating subtress making valid centroid as root
	
	dfs(centroid,-1);
	
	// find the sizes of two maximum subtrees
	
	int max1 = 0, max2 = 0;
	
	for(auto u: e[centroid])
	{
		if(max1<subtree[u])
		{
			max2 = max1;
			max1 = subtree[u];
		}
		else if(max2<subtree[u])
			max2 = subtree[u];
	}
	
	if(n-max1==n/2)
		max2 = n/2;
	
	// checking for each vertex
	
	ans[centroid] = 1;
	
	for(auto u: e[centroid])
		check(u,centroid, subtree[u]==max1?max2:max1);
			 
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
		
		
		
	return 0;
}