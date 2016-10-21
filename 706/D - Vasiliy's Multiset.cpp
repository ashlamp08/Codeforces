#include<bits/stdc++.h>

using namespace std;

class trie{
	public:
	int occ;
	trie *next[2];
	
	trie(){
		occ = 0;
		next[0] = next[1] = NULL;
	}
};

void add(int val, trie *p)
{
	int bin[32];
	
	for(int i=31;i>=0;i--)
	{
		bin[i] = val&1;
		val = val>>1;
	}
	
	for(int i=0;i<32;i++)
	{
		int current = bin[i];
		if(p->next[current]==NULL)
		{
			trie *q = new trie;
			p->next[current] = q;
		}
		p = p->next[current];
		p->occ++;
		
	}
}

int max_xor(int val, trie *p)
{
	int bin[32];
	int number=0;
	
	for(int i=31;i>=0;i--)
	{
		bin[i] = val&1;
		val = val>>1;
	}
	
	for(int i=0;i<32;i++)
	{
		int current = bin[i];
		if(p->next[1-current] && p->next[1-current]->occ)
		{
			number = number<<1;
			number = number|1;
			p = p->next[1 - current];
		}
		else
		{	
			number = number<<1;
			p = p->next[current];
		}
	}
	return number;
}


bool remove_util(int current, int bin[], trie *p)
{	
	if(current==32)
	{
		p->occ--;
		if(p->occ==0)
		{
			//cout<<"deleted";
			//delete p;
			return true;
		}
		return false;
	}
	
	bool accept = remove_util(current+1,bin,p->next[bin[current]]);
	
	//~ if(accept)
		//~ p->next[bin[current]] = NULL;
	
	p->occ--;
	
	if(p->occ==0)
	{ 
		//delete p;
		return true;
	}
	return false;
}
		

void remove(int val, trie *p)
{
	int bin[32];
	
	for(int i=31;i>=0;i--)
	{
		bin[i] = val&1;
		val = val>>1;
	}
	
	remove_util(0, bin,p);
}

int main()
{
	int q;
	cin>>q;
	
	trie *T = new trie;
	add(0,T);
	
	while(q--)
	{
		char a;
		int val;
		cin>>a>>val;
		
		if(a=='+')
			add(val,T);
		else if(a=='-')
			remove(val,T);
		else if(a=='?')
			cout<<max_xor(val,T)<<'\n';
	}
	
	return 0;
}


/*
		
		
6
+ 8
+ 9
+ 11
+ 6
+ 1
? 3		
		
		
		
		
		
		
		
		
		
		

*/