#include<bits/stdc++.h>

using namespace std;

long long arr1[100005], arr2[100005];

long long search(long long x, int beg, int end)
{
	int mid = (beg+end)/2;
	
	if(beg>end)
		return mid;
	
	if(arr2[mid]==x)
		return mid;
	else if(x>arr2[mid])
		return search(x,mid+1,end);
	else 
		return search(x,beg,mid-1);
}		

int main()
{
	int N,M;
	
	cin>>N>>M;
	
	
	for(int i=0;i<N;i++)
		cin>>arr1[i];
	
	for(int i=0;i<M;i++)
		cin>>arr2[i];
		
	sort(arr1,arr1+N);
	sort(arr2,arr2+M);
	
	long long final_ans = -1;
	
	for(int i=0;i<N;i++)
	{
		int ind = search(arr1[i],0,M-1);
		long long ans = 9999999999;
		
		//cout<<ind<<" ";
		
		if(ind>0 && ind<M-1)
		{
			ans = min(ans, abs(arr1[i] - arr2[ind]));
			ans = min(ans, abs(arr1[i] - arr2[ind+1]));
			ans = min(ans, abs(arr1[i] - arr2[ind-1]));
		}
		else if(ind==0 && ind<M-1)
		{
			ans = min(ans, abs(arr1[i] - arr2[ind]));
			ans = min(ans, abs(arr1[i] - arr2[ind+1]));
		}
		else if(ind==M-1 && ind>0)
		{
			//cout<<"hello  ";
			ans = min(ans, abs(arr1[i] - arr2[ind]));
			ans = min(ans, abs(arr1[i] - arr2[ind-1]));
			//cout<<ans<<" ";
		}
		else
			ans = min(ans, abs(arr1[i] - arr2[ind]));
		
		final_ans = max(final_ans,ans);	
	}

	cout<<final_ans;

	return 0;
}