#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int T;
	cin>>T;
	
	map<string,int> M;
	
	for(int i=0;i<T;i++)
	{
		char c;
		cin>>c;
		
		if(c=='+')
		{
			ll a;
			cin>>a;
			
			char b[20];
			b[18] = '\0';
			
			for(int j=17;j>=0;j--)
			{
				b[j] = '0' + (a&1);
				a/=10;
			}
			
			//cout<<"b  "<<b<<endl;
			
			M[b]++;
		}
		else if(c=='-')
		{
			ll a;
			cin>> a;
			char b[20];
			b[18] = '\0';
			
			for(int j=17;j>=0;j--)
			{
				b[j] = '0' + (a&1);
				a/=10;
			}
			
			//cout<<"b  "<<b<<endl;
			
			M[b]--;
		}
		else
		{
			string c;
			cin>>c;
			
			int sz = c.size(); 
			
			char d[20];
			
			for(int k=0;k<18-sz;k++)
				d[k] = '0';
			
			for(int k=18-sz,j=0;c[j];k++,j++)
				d[k] = c[j];
				
			d[18] = '\0';
			
			//cout<<"d  "<<d<<endl;
			
			cout<<M[d]<<'\n';
		}
	}
	return 0;
}