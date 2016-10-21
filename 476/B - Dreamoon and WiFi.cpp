#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

#define M 1000000007

long long ncr[1003][1003] = {0};

void init_ncr(int n)
{
	ncr[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		ncr[i][0] = ncr[i][i] = 1;
		for(int j=1;j<i;j++)
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%M;
	}
}

int abso(int x)
{
	if(x<0)
		return -x;
	else
		return x;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	init_ncr(15);
	
	string s1,s2;
	
	cin>>s1>>s2;
	
	int stat1,stat2,ques;
	stat1 = stat2 = ques = 0;
	
	int n = s1.length();
	
	for(int i=0;i<n;i++)
	{
		if(s1[i] == '+')
			stat1++;
		if(s1[i] == '-')
			stat1--;
		if(s2[i] == '+')
			stat2++;
		if(s2[i] == '-')
			stat2--;
		if(s2[i] == '?')
			ques++;
	}
	
	int curr = stat1 - stat2;
	double ans = 0.0;
	
	if((abso(curr)>ques) || ((ques-curr)%1)&1)
		cout<<std::setprecision(9)<<ans<<'\n';
	else 
	{
		cout<<std::setprecision(9)<<ncr[ques][(ques-curr)/2]*pow(0.5,ques)<<'\n';
	}
	
	return 0;
}