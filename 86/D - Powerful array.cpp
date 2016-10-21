#include<bits/stdc++.h>

using namespace std;

long long arr[200005];
long long cnt[1<<20];
long long answers[200005];
long long current_ans = 0;
long long BLOCK_SIZE = 0;

struct query{
	int l;
	int r;
	int pos;
};

bool mo_comperator (query i,query j) 
{ 
    return ((i.l / BLOCK_SIZE) != (j.l / BLOCK_SIZE)) ? i.l < j.l : i.r < j.r;
}

void add(long long x)
{
	current_ans += x * (2*cnt[x] + 1);
	cnt[x]++;
}

void remove(long long x)
{
	current_ans += x * (1 - 2*cnt[x]);
	cnt[x]--;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n,m,l,r;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	BLOCK_SIZE = (long long)sqrt(n);
	query q[m+4];
	
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		q[i].l = l; q[i].r = r; q[i].pos = i;
	}

	sort(q,q+m,mo_comperator);
	
	int curr_left = 0;
	int curr_right = 0;
	int left,right;

	for(int i=0;i<m;i++)
	{
		left = q[i].l;
		right = q[i].r;
		
		while(curr_left<left)
		{
			current_ans += arr[curr_left] * (1 - 2*cnt[arr[curr_left]]);
			cnt[arr[curr_left]]--;
			curr_left++;
		}
		while(curr_left>left)
		{
			--curr_left;
			current_ans += arr[curr_left] * (2*cnt[arr[curr_left]] + 1);
			cnt[arr[curr_left]]++;
		}
		while(curr_right<right)
		{
			++curr_right;
			current_ans += arr[curr_right] * (2*cnt[arr[curr_right]] + 1);
			cnt[arr[curr_right]]++;
		}
		while(curr_right>right)
		{
			current_ans += arr[curr_right] * (1 - 2*cnt[arr[curr_right]]);
			cnt[arr[curr_right]]--;
			curr_right--;
		}

		answers[q[i].pos] = current_ans;
	}
	
	for(int i=0;i<m;i++)
		cout<<answers[i]<<'\n';
		
	return 0;
}