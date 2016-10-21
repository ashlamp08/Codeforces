#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n;
	cin>>n;

	ll a[n];
	
	ll sum[n+1];
	sum[0] = 0;
	
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
		sum[i+1] = sum[i] + a[i];
	}
	
	map<int,int> done;
	
	done[n+1] = 1;
	done[0] = 1;
	
	set<pair<ll,pair<int,int>>> SS;
	SS.insert({sum[n],{0,n+1}});
	
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		
		done[p] = 1;
		
		auto it = done.find(p);
		
		int a = (--it)->first;
		it++;
		int b = (++it)->first;
		
		SS.erase({sum[b-1]-sum[a],{a,b}});
		
		//~ cout<<sum[b-1]-sum[a]<<"  "<<a<<"  "<<b<<endl;
		
		ll yy = sum[b-1] - sum[p];
		ll xx = sum[p-1] - sum[a];
		
		//~ cout<<xx<<"  "<<a<<"  "<<p<<endl;
		//~ cout<<yy<<"  "<<p<<"  "<<b<<endl;
		
		SS.insert({xx,{a,p}});
		SS.insert({yy,{p,b}});
		//~ cout<<SS.size()<<endl;
		cout<<(--SS.end())->first<<'\n';
	}
	return 0;
}