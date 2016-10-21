#include<bits/stdc++.h>

using namespace std;

vector<int> e[100005];
int stree[100005];
double ans[100005];

int dfs(int u, int p)
{
	stree[u] = 1;
	
	for(auto v: e[u])
	{
		if(v!=p)
			stree[u] += dfs(v,u);
	}
	return stree[u];
}

void solve(int u, int p)
{	
	for(auto v: e[u])
	{
		if(v!=p)
		{
			ans[v] = ans[u] + 1.0 + 0.5*(stree[u] - stree[v] - 1.0);
			solve(v,u);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		int a;
		cin>>a;
		a--;
		
		e[i].push_back(a);
		e[a].push_back(i);
	}
	
	dfs(0,-1);
	
	ans[0] = 1.0;
	
	solve(0,-1);
	
	cout<<setprecision(7);
		
	for(int i=0;i<n;i++)
		cout<<fixed<<ans[i]<<" ";
		
	return 0;
}