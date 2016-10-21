#include<bits/stdc++.h>

using namespace std;

long long n;
int robots[100005] = {0};
int x[100005],y[100005];
int root = 0;
vector<int> graph[100005];
vector<int> time_graph[100005];
vector<int> time_stack;
bool visited[100005] = {false};
map<pair<int,int>,int> mp;

int find_robot()
{
	for(int i=0;i<n;i++)
	{
		if(!robots[i])
			return i;
	}
	return 0;
}

void dfs(int u, vector<int> graph[])
{
	visited[u] = true;
	int size = graph[u].size();

	int v;
	
	for(int i=0;i<size;i++)
	{
		v = graph[u][i];
		if(!visited[v])
		{	
			dfs(v,graph);
			time_stack.push_back(v);
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long m,u,v;
	
	cin>>n>>m;
	
	long long size = n;
	
	for(int i=0;i<m;i++)
	{
		cin>>x[i]>>y[i];
		x[i]--;
		y[i]--;
	}
	
	int curr = 0;
	
	for(curr=0;curr<m;curr++)
	{
		if(!robots[y[curr]])
		{
			robots[y[curr]] = 1;
			size--;
		}
		if(size==1)
		{
			root = find_robot();
			break;
		}
	}
	
	if(curr==m)
	{
		cout<<-1;
		return 0;
	}
	
	for(int i=0;i<m;i++)
	{
		u = x[i];
		v = y[i];
		graph[u].push_back(v);
		
		mp[{u,v}] = i+1;
		
		if(!robots[y[i]])
		{
			robots[y[i]] = 1;
			size--;
		}
		if(size==0)
		{
			cout<<-1;
			return 0;
		}
	}
		
	dfs(root,graph);		
	time_stack.push_back(root);	
	
	//~ cout<<time_stack.size()<<'\n';	
			
	if(time_stack.size()==(unsigned)n)
	{	
		int ans = -1;
		
		for(int i=0;i<n-1;i++)
		{
			map<pair<int,int>,int>::iterator it = mp.find({time_stack[i+1],time_stack[i]});
			if(it==mp.end())
			{
				cout<<-1;
				return 0;
			}
		}
		
		for(int i=0;i<n-1;i++)
		{
			if(mp[{time_stack[i+1],time_stack[i]}]>ans)
				ans = mp[{time_stack[i+1],time_stack[i]}];
		}
		
		cout<<ans;
	}
	else
		cout<<-1;

	return 0;
}