#include<iostream>
#include<utility>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

long long ans = 0;

template <class t1, class t2>
class Graph
{
	public:
	vector< pair<t1,t2> > node[200005];
	bool visited[200005];
	stack<int> stk;

	void init()
	{
		memset(visited,false,200005);
		while(!stk.empty())
			stk.pop();
	}
	
	void add_edge(int u, int v, int w)
	{
		pair<t1,t2> p;
		p = make_pair(v,w);
		node[u].push_back(p);
	}
	
	void show_graph()
	{ 
		for(int i=0;i<10;i++)
		{
			int size = node[i].size();
			cout<<i<<" -> ";
			for(int j=0;j<size;j++)
				cout<<"("<<node[i][j].first<<','<<node[i][j].second<<")"<<" -> ";
			cout<<"x\n";
		}
	}
	
	long long dfs(int v, int parent)
	{
		int size,temp;
		int left_edges = 2;
		size = node[v].size();

		for(int j=0;j<size;j++)
		{	
			if(node[v][j].first!=parent)
			{	
				temp = dfs(node[v][j].first,v);
				if(left_edges>0 && temp)
				{
					ans++;
					left_edges--;
				}
			}
		}
		
		if(left_edges>0)
			return 1;
		else
			return 0;
	}	
};	

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N,x,y,a,b;
	
	cin>>N>>x>>y;
	Graph<long long,long long> G;
	
	G.init();
	
	for(int i=0;i<N-1;i++)
	{
		cin>>a>>b;
		G.add_edge(a,b,x);
		G.add_edge(b,a,x);
	}
	
	if(x>y)
	{
		bool flag = false;
		for(int i=1;i<=N;i++)
		{
			if(G.node[i].size()==(unsigned)(N-1))
			{
				flag = true;
				break;
			}
		}
		
		if(flag)
			cout<<(N-2)*y+x<<'\n';
		else
			cout<<(N-1)*y<<'\n';
	}
	else
	{	
		ans = 0;
		G.dfs(1,-1);
		
		cout<<ans*x + (N-1-ans)*y<<'\n';
	}
		
	return 0;
}