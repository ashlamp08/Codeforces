#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll,ll>

bool comp(pll a, pll b)
{
	if(a.first==b.first)
		return a.second<b.second;
	else
		return a.first<b.first;
}

int main()
{
	int n;
	cin>>n;
	
	pll a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
		
	int m;
	cin>>m;
	
	pll b[m];
	
	for(int i=0;i<m;i++)
		cin>>b[i].first>>b[i].second;

	pll c[n+m];	
		
	for(int i=0;i<n;i++)
		c[i].first = a[i].first, c[i].second = a[i].second;
		
	for(int i=n;i<n+m;i++)
		c[i].first = b[i-n].first, c[i].second = b[i-n].second;
		
	sort(c,c+n+m,comp);
	
	//~ cout<<"C\n";
	//~ for(int i=0;i<n+m;i++)
		//~ cout<<c[i].first<<"  "<<c[i].second<<'\n';
	
	vector<pll> CHupper;
	vector<pll> CHlower;
	
	CHupper.push_back(c[0]);
	CHupper.push_back(c[1]);
	
	for(int i=2,j=2;i<n+m;i++,j++)
	{
		while(j>1 && (CHupper[j-1].second-CHupper[j-2].second)*(c[i].first-CHupper[j-1].first) < (c[i].second-CHupper[j-1].second)*(CHupper[j-1].first-CHupper[j-2].first))	
		{
			j--;
			CHupper.pop_back();
		}
		
		CHupper.push_back(c[i]);
	}
	
	CHlower.push_back(c[0]);
	CHlower.push_back(c[1]);
	
	for(int i=2,j=2;i<n+m;i++,j++)
	{
		while(j>1 && (CHlower[j-1].second-CHlower[j-2].second)*(c[i].first-CHlower[j-1].first) > (c[i].second-CHlower[j-1].second)*(CHlower[j-1].first-CHlower[j-2].first))	
		{
			j--;
			CHlower.pop_back();
		}
		
		CHlower.push_back(c[i]);
	}
	
	vector<pll> hull;
	
	for(unsigned int i=0;i<CHupper.size();i++)
		hull.push_back(CHupper[i]);

	for(unsigned int i=1;i<CHlower.size()-1;i++)
		hull.push_back(CHlower[i]);
	
	if((unsigned int)n!=hull.size())
	{	
		cout<<"NO";
		return 0;
	}
	
	sort(a,a+n,comp);
	sort(hull.begin(),hull.end(),comp);
	
	for(int i=0;i<n;i++)
	{
		if(a[i]!=hull[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	
	cout<<"YES";
	
	return 0;
}