#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>

pii edge[200010];
vector<int> G[100005];
ll dist[100005];
int p[100005];
ll w[200010];
int n,m;
ll inf = (ll)1e15;

void djk(int s)
{
	set<pli> S;
	fill(dist, dist+n, inf);
	
	dist[s] = 0; 
	p[s] = -1;

	for(int i=0;i<n;i++)
	{
		if(i!=s)
			S.insert({inf,i});
		else
			S.insert({0,i});
	}
	
	
	
	while(S.size())
	{
		int u = S.begin()->second;
		S.erase(S.begin());
		
		for(auto e: G[u])
		{
			int v = edge[e].first + edge[e].second - u;
			//~ cerr<<u+1<<" "<<v+1<<" "<<dist[u] + w[e]<<" "<<dist[v]<<endl;
			
			if(dist[v] > dist[u] + w[e])
			{
				S.erase({dist[v],v});
				dist[v] = dist[u] + w[e];
				S.insert({dist[v],v});
				p[v] = u;
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		ll c;
		cin>>a>>b>>c;
		
		a--,b--;
		
		G[a].push_back(i);
		G[b].push_back(i);
		
		edge[i].first = a;
		edge[i].second = b;
		
		w[i] = c;
	}
	
	djk(0);
	
	if(dist[n-1]==inf)
		cout<<"-1";
	else
	{
		stack<int> SS;
		int v = n-1;
		while(v!=-1)
			SS.push(v),v=p[v];
				
		while(SS.size())
		{
			cout<<SS.top()+1<<" ";
			SS.pop();
		}
	}
	
	return 0;
}