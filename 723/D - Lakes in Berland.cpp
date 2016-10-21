#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<int,int>> G[50][50];
char a[55][55];
int lake[55][55]= {0};
int visited[55][55] = {0};

int dfs(int i,int j)
{
	visited[i][j] = 1;
	int res = 1;
	
	for(auto u: G[i][j])
	{
		if(!visited[u.first][u.second])
			res += dfs(u.first,u.second);
	}
	
	return res;
}

void ocean(int i,int j)
{
	visited[i][j] = 1;
	lake[i][j] = 2;
	
	for(auto u: G[i][j])
	{
		if(!visited[u.first][u.second])
			 ocean(u.first,u.second);
	}
}

void fill(int i,int j)
{
	visited[i][j] = 0;
	a[i][j] = '*';
	
	for(auto u: G[i][j])
	{
		if(visited[u.first][u.second])
			 fill(u.first,u.second);
	}
}	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int n,m,k;
	
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
		{	
			if(i>0 && a[i][j]=='.' && a[i-1][j]=='.')
				lake[i][j] = 1, G[i][j].push_back({i-1,j}), G[i-1][j].push_back({i,j});
			if(j>0 && a[i][j]=='.' && a[i][j-1]=='.')
				lake[i][j] = 1, G[i][j].push_back({i,j-1}), G[i][j-1].push_back({i,j});
			if(a[i][j]=='.')
				lake[i][j] = 1;
		}
	}
		
	for(int i=0;i<m;i++)
	{	
		if(a[0][i]=='.' && !visited[0][i])
			ocean(0,i);
		if(a[n-1][i]=='.' && !visited[n-1][i])
			ocean(n-1,i);
	}
	
	for(int i=0;i<n;i++)
	{	
		if(a[i][0]=='.' && !visited[i][0])
			ocean(i,0);
		if(a[i][m-1]=='.' && !visited[i][m-1])
			ocean(i,m-1);
	}
							
	set<pair<int,pair<int,int>>> S;
	
	//~ for(int i=0;i<n;i++)
	//~ {	
		//~ for(int j=0;j<m;j++)
			//~ cout<<lake[i][j];
		//~ cout<<endl;
	//~ }
	
	for(int i=1;i<n-1;i++)
		for(int j=1;j<m-1;j++)
			if(lake[i][j]==1 && !visited[i][j])
				S.insert({dfs(i,j),{i,j}});
	
	int ans = 0;			
	int c = S.size() - k;
				
	for(int i=0;i<c;i++)
	{
		int a = (*(S.begin())).second.first;
		int b = (*(S.begin())).second.second;
		
		ans+= (*(S.begin())).first;
		
		fill(a,b);
		
		S.erase(S.begin());
	}
		
	cout<<ans<<'\n';
	
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
			cout<<a[i][j];
		cout<<endl;
	}
	
	return 0;
}