#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char S[200005];
	
	cin>>S;
	
	long long len = strlen(S);
	
	char temp1[len];
	char temp2[len];
	
	long long count = 1;

	temp1[0] = S[0];
	
	for(int i=1,j=1;i<len;i++)
	{
		if(S[i]==S[i-1])
			count++;
		else
			count = 1;
		if(count<=2)
			temp1[j++] = S[i];
		if(i==len-1)
			temp1[j] = '\0';
	}
	
//	cout<<temp1;

	len = strlen(temp1);
	long long occ = 0;
		
	count = 1;

	temp2[0] = temp1[0];
	
	for(int i=1,j=1;i<len;i++)
	{
		if(temp1[i]==temp1[i-1])
		{	
			count++;
			occ++;
		}
		else
		{	
			if(count&1)
				occ=0;
			count = 1;
		}
		
		temp2[j++] = temp1[i];
		
		if(!(occ&1) && !(count&1))
			j--;
		
	//	cout<<occ<<'\n';
	
		if(i==len-1)
			temp2[j] = '\0';
	}
	
	cout<<temp2;
	
		
	
	return 0;
}