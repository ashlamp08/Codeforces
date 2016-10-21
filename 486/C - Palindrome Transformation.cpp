#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,p;
	
	cin>>n>>p;
	
	p--;
	
	string A;
	
	cin>>A;
	
	int diff[n];
	
	memset(diff,0,n*sizeof(int));
	
	for(int i=0;i<(n/2);i++)
	{
		diff[i] = min(26 - abs((int)(A[i]-A[n-1-i])),abs((int)(A[n-i-1]-A[i])));
	}
	
/*	for(int i=0;i<n;i++)
		cout<<diff[i]<<' ';*/
		
	if(p>=(n/2))
		p = (n-1 - p);

	int right;
	int left;
	
	
		right = n/2;
	
	while(right>0)
	{
		if(diff[right])
			break;
		right--;
	}
	
	left = 0;
	while(left<right)
	{
		if(diff[left])
			break;
		left++;
	}
	
//	cout<<'\n'<<left<<" l "<<right<<"  "<<p<<'\n';
		
	long long ans = 0;
	for(int i=left;i<=right;i++)
		ans+=diff[i];
	
	ans+=(right-left);
	
	if(ans)
		ans+=min(abs(right-p),abs(p-left));

	cout<<ans;
	
	return 0;
}