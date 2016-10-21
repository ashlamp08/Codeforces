#include<bits/stdc++.h>

using namespace std;

long long arr[100005];
long long pre[100005];
long long k;
long long cnt[1<<20]={0};
long long answers[100005];
long long current_ans = 0;
long long BLOCK_SIZE = 0;

struct query{
	int l;
	int r;
	int pos;
} q[100005];

bool mo_comperator (query i,query j) 
{ 
	int block_i = i.l / BLOCK_SIZE;
    int block_j = j.l / BLOCK_SIZE;
    if(block_i != block_j)
        return block_i < block_j;
    return i.r < j.r;
}

void add(long long x)
{
	current_ans += cnt[x ^ k];	
	cnt[x]++;
	//~ cout<<x<<"  "<<cnt[x]<<"  "<<current_ans<<'\n';
}

void remove(long long x)
{
	cnt[x]--;
	current_ans -= cnt[x ^ k];
	//~ cout<<x<<"  "<<cnt[x]<<"  "<<current_ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m,l,r;
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	pre[0] = 0;	
	for(int i=1;i<=n;i++)
		pre[i] = pre[i-1]^arr[i];
	
	BLOCK_SIZE = (long long)sqrt(n);
	
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		q[i].l = --l;
		q[i].r = r;
		q[i].pos = i;
	}
	
	sort(q,q+m,mo_comperator);
	
	//~ for(int i=0;i<m;i++)
	//~ {
		//~ cout<<q[i].l<<"  "<<q[i].r<<'\n';
	//~ }
	
	int curr_left = 0;
	int curr_right = -1;

	for(int i=0;i<m;i++)
	{
		int left = q[i].l;
		int right = q[i].r;
		
		//~ cout<<"lr  "<<q[i].l<<"  "<<q[i].r<<'\n';
		
		while(curr_right<right)
		{
			curr_right++;
			add(pre[curr_right]);
		}
		
		while(curr_right>right)
		{
			remove(pre[curr_right]);
			curr_right--;
		}
		
		while(curr_left<left)
		{
			remove(pre[curr_left]);
			curr_left++;
		}
		
		while(curr_left>left)
		{
			curr_left--;
			add(pre[curr_left]);
		}
		
		answers[q[i].pos] = current_ans;
	}
	
	for(int i=0;i<m;i++)
		cout<<answers[i]<<'\n';
		

	return 0;
}
	
/*
 * 
 * 10 7 3
1 2 3 4 5 6 7 8 9 10
0 3
1 7
2 8
7 8
 4 8
4 4
1 2
* 
* 
* 50 4 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
17 35
3 35
33 42
20 27

* 
*/