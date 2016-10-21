#include<bits/stdc++.h>

using namespace std;

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie();
	
	long double a,b;
	int N;
	
	cin>>a>>b>>N;
	
	double x,y,v,min_time,t;
	
	min_time = 999999999.0;
	
	for(int i=0;i<N;i++)
	{
		cin>>x>>y>>v;
		
		t = pow((pow(x-a,2) + pow(y-b,2)),0.5)/v;
		
		if(t<min_time)
			min_time = t;
	}
	
	printf("%.12lf",min_time);
	
	return 0;
}