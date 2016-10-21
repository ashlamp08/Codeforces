#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N,p;
	cin>>N>>p;
	
	long double exp = 0.0;
	
	long long count[N],l,r;
	long long tot[N];
	
	for(int i=0;i<N;i++)
	{	
		cin>>l>>r;
		count[i] = r/p - (l-1)/p;
		tot[i] = (r-l+1);
	}
	
/*	for(int i=0;i<N;i++)
		cout<<prob[i]<<'\n';*/
	
	for(int i=0,j=1;i<N;i++,j++)
	{
		if(j==N) 
			j = 0; 
		exp += (2000.0 - 2000.0*(1.0 - (double)count[i]/(double)tot[i])*(1.0 - (double)count[j]/(double)tot[j]));
	}
	
	cout<<setprecision(7)<<fixed;
	cout<<exp<<'\n';
	
	return 0;
	
}