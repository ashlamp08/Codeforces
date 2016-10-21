#include<bits/stdc++.h>

using namespace std;

deque<int> pos[300006];
bool read[300006] = {false};

int main()
{
	//~ ios_base::sync_with_stdio(0);
	//~ cin.tie(0);
	
	int N,Q,a,b;
	cin>>N>>Q;
	
	vector<int> queue;
	long long unread = 0;
	int last = -1;
	
	while(Q--)
	{
		cin>>a>>b;
		
		if(a==1)
		{
			queue.push_back(b);
			pos[b].push_back(queue.size()-1);
			unread++;
			
			cout<<unread<<'\n';
		}
		else if(a==2)
		{
			int sz = pos[b].size();
			
			for(int j=0;j<sz;j++)
			{
				read[pos[b][0]] = true;
				unread--;
				pos[b].pop_front();

			}
			
			cout<<unread<<'\n';
		}
		else
		{
			for(int j=last+1;j<b;j++)
			{
				if(read[j])
					continue;
				read[j] = true;
				pos[queue[j]].pop_front();
				unread--;
			}
			
			if(last<(b-1))
				last = b-1;
				
			cout<<unread<<'\n';
		}
	}
	
	return 0;
}