#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>

int n;
int inf = (int)1e9 + 5;
vector<int> e[1003];
vector<int> wt;
vector<pii> sides;
bool erased[10004]={false};
int dist1[1003];
int dist2[1003];
int need;


void dijkstra1(int s)
{
	set<pii> pq;
	fill(dist1, dist1+n, inf);
	dist1[s] = 0;
	for(int i=0;i<n;i++)
		pq.insert({dist1[i],i});
	while(pq.size())
	{
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		int sz = e[u].size();
		for(int i=0;i<sz;i++)
		{
			int edge = e[u][i];
			int v = sides[edge].first + sides[edge].second - u;
			
			if(dist1[v] > dist1[u]+wt[edge])
			{
				pq.erase({dist1[v],v});
				dist1[v] = dist1[u] + wt[edge];
				pq.insert({dist1[v],v});
			}
		}
	}
}
			
void dijkstra2(int s)
{
	set<pii> pq;
	fill(dist2, dist2+n, inf);
	dist2[s] = 0;
	for(int i=0;i<n;i++)
		pq.insert({dist2[i],i});
	while(pq.size())
	{
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		int sz = e[u].size();
		for(int i=0;i<sz;i++)
		{
			int edge = e[u][i];
			int v = sides[edge].first + sides[edge].second - u;
			
			if((dist2[v] > dist2[u]+wt[edge]) && erased[edge] && dist1[v]+need>dist2[u]+wt[edge])
				wt[edge] = dist1[v] + need - dist2[u];
			if((dist2[v] > dist2[u]+wt[edge]))
			{
				pq.erase({dist2[v],v});
				dist2[v] = dist2[u] + wt[edge];
				pq.insert({dist2[v],v});
			}
		}
	}
}			
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int m,s,t;
	int L;
	
	cin>>n>>m>>L>>s>>t;
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;

		cin>>a>>b>>c;	
		
		sides.push_back({a,b});
		
		if(!c)
		{	
			erased[i] = true;
			c = 1;
		}
		
		wt.push_back(c);
		e[a].push_back(i);
		e[b].push_back(i);
	}
	
	dijkstra1(s);
	//~ for(int i=0;i<n;i++)
		//~ cout<<dist1[i]<<" ";
	if(dist1[t] > L)
		cout<<"NO\n";
	else
	{
		need = L-dist1[t];
		dijkstra2(s);
		if(dist2[t]<L)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			for(int i=0;i<m;i++)
				cout<<sides[i].first<<" "<<sides[i].second<<" "<<wt[i]<<'\n';
		}
	}
	
	return 0;
}