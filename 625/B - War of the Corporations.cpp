#include<bits/stdc++.h>

using namespace std;

int compare(char A[], char B[], int i)
{
	for(int j=i,k=0;B[k]!='\0';j++,k++)
	{
		if(A[j]!=B[k])
			return 0;
	}
	return 1;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char A[100005], B[100005];
	
	cin>>A>>B;
	
	long long la,lb;
	
	long long count = 0;
	
	la = strlen(A);
	lb = strlen(B);	
	
	if(la<lb)
		cout<<0;
	else
	{
		for(int i=0;i<(la-lb+1);)
		{
			if(compare(A,B,i))
			{
				count++;
				i = i+lb;
			}
			else
				i++;
		}
		cout<<count;
	}
	
	return 0;
}