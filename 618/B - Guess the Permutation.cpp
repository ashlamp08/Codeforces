#include<bits/stdc++.h>

using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N;
	
	cin>>N;
	
	int max_arr[N];
	
	memset(max_arr,-1,N*sizeof(int));
	
	for(int i=0;i<N;i++)
	{
		int temp;
		for(int j=0;j<N;j++)
		{
			cin>>temp;
			if(temp>max_arr[i])
				max_arr[i] = temp;
		}
	}
	
	int flag = false;
	
	for(int i=0;i<N;i++)
	{
		if(max_arr[i]==(N-1))
		{
			if(flag)
				cout<<N<<" ";
			else
			{
				cout<<max_arr[i]<<" ";
				flag = true;
			}
		}
		else
			cout<<max_arr[i]<<" ";
	}
	
	return 0;
}