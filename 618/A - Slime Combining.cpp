#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N;
	
	cin>>N;
	
	int place = 0;
	
	v.push_back(1);
	
	for(int i=0;i<N-1;i++)
	{
		v.push_back(1);
		place++;

			while(place && v[place]==v[place-1])
			{
				v.pop_back();
				place--;
				v[place]++;
			}

	}
	
	for(int i=0;i<=place;i++)
		cout<<v[i]<<" ";
		
	return 0;
}