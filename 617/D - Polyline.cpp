#include<iostream>
#include<string>
#include<set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long x[4],y[4];

	std::set<long long> myset1,myset2;


	for (int i=1; i<=3; i++) 
	{
		cin>>x[i];
		cin>>y[i];
		myset1.insert(x[i]);
		myset2.insert(y[i]);
	}
	
	if(myset1.size()==1 || myset2.size()==1)
		cout<<1<<'\n';
	else if(myset1.size()==2 || myset2.size()==2)
	{
		if(myset2.size()==2)
		{
			if(((x[1]<x[2] && x[2]<x[3]) || (x[1]>x[2] && x[2]>x[3])) && y[1]==y[3])
				cout<<3<<'\n';
			else if(((x[2]<x[1] && x[1]<x[3]) || (x[2]>x[1] && x[1]>x[3])) && y[2]==y[3])
				cout<<3<<'\n';
			else if(((x[1]<x[3] && x[3]<x[2]) || (x[1]>x[3] && x[3]>x[2])) && y[1]==y[2])
				cout<<3<<'\n';
			else
				cout<<2<<'\n';
		}
		else if(myset1.size()==2)
		{
			if(((y[1]<y[2] && y[2]<y[3]) || (y[1]>y[2] && y[2]>y[3])) && x[1]==x[3])
				cout<<3<<'\n';
			else if(((y[2]<y[1] && y[1]<y[3]) || (y[2]>y[1] && y[1]>y[3])) && x[2]==x[3])
				cout<<3<<'\n';
			else if(((y[1]<y[3] && y[3]<y[2]) || (y[1]>y[3] && y[3]>y[2])) && x[1]==x[2])
				cout<<3<<'\n';
			else
				cout<<2<<'\n';
		}		
	}
	else
		cout<<3<<'\n';
		
	return 0;
}