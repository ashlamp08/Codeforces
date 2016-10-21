#include<iostream>
#include<utility>
#include<string>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

template <class t1, class t2>
class Graph
{
	private:
	vector< pair<t1,t2> > node[100005];
	bool visited[100005];
	stack<int> stk;
	
	public:
	void init()
	{
		memset(visited,false,100005);
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
	
	long long dfs(int i)
	{
		int size,v;
		long long sum = 0;
		
		memset(visited,false,2003*sizeof(bool));
			
		stk.push(i);           
		visited[i] = true;
		
		while (!stk.empty())
		{
			// pop a vertex from stack to visit next
			v  =  stk.top();
			
			stk.pop();
			sum++;
 
			//push all the neighbours of v in stack that are not visited
			size = node[v].size();
			for(int j=0;j<size;j++)
			{	
				if(!visited[node[v][j].first])
				{	
					stk.push(node[v][j].first);         
					visited[node[v][j].first] = true;
				}
			}
		}		
		return sum;
	}	
};	

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N,x,max,a;
	
	max = -1;

		cin>>N;
		Graph<int,int> G;
		
		G.init();
		
		for(int i=1;i<=N;i++)
		{	
			cin>>x;
			if(x!=-1)
				G.add_edge(i,x,0);
		}
			
		for(int i=1;i<=N;i++)
		{
			a = G.dfs(i);
			if(a>max)
				max = a;
		}
		
		cout<<max<<'\n';

	
	return 0;
}