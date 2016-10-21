#include<bits/stdc++.h>

using namespace std;

#define ll long long

pair<ll,ll> point[100005];

map<pair<ll,ll>,ll> com;

bool myfunction (pair<ll,ll> i,pair<ll,ll> j) 
{ 
	if(i.first<j.first)
		return 1;
	else if((i.first==j.first) && (i.second<=j.second))
		return 1;
	else 
		return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll N,x,y;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>x>>y;
		
		point[i] = std::make_pair(x,y);
		com[point[i]] = i+1;
	}
	
	sort(point, point+N, myfunction);
	
/*	for(int i=0;i<N;i++)
	{
		cout<<point[i].first<<"   "<<point[i].second<<'\n';
	}*/
	
		if(point[0].first == point[1].first)
		{	
			for(int j=1;j<N-1;j++)
			{
				if(point[j].first != point[j+1].first)
				{
					cout<<com[point[0]]<<" "<<com[point[1]]<<" "<<com[point[j+1]];
						return 0;
				}
			}
		}
		else
		{
				
				cout<<com[point[0]]<<" "<<com[point[1]]<<" ";
				
				int i=2;
				
				if(point[1].second != point[0].second)
				{	
					while((point[1].second - point[0].second)*(point[i].first - point[1].first) == (point[i].second - point[1].second)*(point[1].first - point[0].first))
						i++;
					cout<<com[point[i]];
					return 0;
				}
				else
				{	
				//	cout<<"hello"<<'\n';
					if(point[1].second == point[0].second)
					{
					while((point[1].second - point[0].second)*(point[i].first - point[1].first) == (point[i].second - point[1].second)*(point[1].first - point[0].first))
						i++;
					}
					cout<<com[point[i]];
				}
					return 0;					
					
		}
	
	return 0;
}