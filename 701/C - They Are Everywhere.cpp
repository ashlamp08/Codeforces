#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	set<int> pokemon;
	
	for(int i=0;i<n;i++)
		pokemon.insert(s[i]);
		
	int total = pokemon.size();
	
	int c = 0;
	int r = 0;
	int ans = 1e8;
	int freq[200]={0};
	
	for(int i=0;i<n;i++)
	{
		while(r<n && c<total)
		{
			freq[(int)s[r]]++;
			
			if(freq[(int)s[r]]==1)
				c++;
			
			r++;
		}
		
		if(c==total)
			ans = min(ans,r-i);
		
		freq[(int)s[i]]--;
		
		if(freq[(int)s[i]]==0)
			c--;
	}
	
	cout<<ans;
	
	return 0;
}