#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long double a[13];
	
	long double x,y,z,d,b,c;
	
	cin>>x>>y>>z;
	
	bool flag = false;
	
	if(x<=1 && y<=1 && z<=1)
		flag = true;
		
	b = x;
	if(flag)
		x = 1.0/x;		
	
	if(x>1)
	{
		a[1] = z*log(y) + log(log(x));
		a[2] = y*log(z) + log(log(x));
		a[3] = log(y) + log(z) + log(log(x));
		a[4] = a[2];
	}
	else
		a[1] = a[2] = a[3] = a[4] = -999999;
		
	x = b;
	
	c = y;
	if(flag)
		y = 1.0/y;
	
	if(y>1)
	{
		a[5] = z*log(x) + log(log(y));
		a[6] = x*log(z) + log(log(y));
		a[7] = log(x) + log(z) + log(log(y));
		a[8] = a[7];
	}
	else
		a[5] = a[6] = a[7] = a[8] = -999999;
		
	y = c;
	
	d = z;
	if(flag)
		z = 1.0/z;
	
	if(z>1)
	{
		a[9] = y*log(x) + log(log(z));
		a[10] = x*log(y) + log(log(z));
		a[11] = log(x) + log(y) + log(log(z));
		a[12] = a[11];
	}
	else
		a[9] = a[10] = a[11] = a[12] = -999999;
		
	z = d;
		
	int pos = 1;
	long double max=a[1];
	
	if(x<=1 && y<=1 && z<=1)
	{
	for(int i=1;i<=12;i++)
	{
		//cout<<a[i]<<" ";
		if(max>a[i])
		{
			max = a[i];
			pos = i;
		}
	}
	}
	else
	{
	for(int i=1;i<=12;i++)
	{
		//cout<<a[i]<<" ";
		if(max<a[i])
		{
			max = a[i];
			pos = i;
		}
	}
	}
	
	
	switch(pos)
	{
		case 1: cout<<"x^y^z"<<'\n'; break;
		case 2: cout<<"x^z^y"<<'\n'; break;
		case 3: cout<<"(x^y)^z"<<'\n'; break;
		case 4: cout<<"(x^z)^y"<<'\n'; break;
		case 5: cout<<"y^x^z"<<'\n'; break;
		case 6: cout<<"y^z^x"<<'\n'; break;
		case 7: cout<<"(y^x)^z"<<'\n'; break;
		case 8: cout<<"(y^z)^x"<<'\n'; break;
		case 9: cout<<"z^x^y"<<'\n'; break;
		case 10: cout<<"z^y^x"<<'\n'; break;
		case 11: cout<<"(z^x)^y"<<'\n'; break;
		case 12: cout<<"(z^y)^x"<<'\n'; break;
		default: break;
	}
	
	return 0;
}