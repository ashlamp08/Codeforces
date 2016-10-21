#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll; 

struct two{
	ll a;
	ll b;
};

bool fncomp (two lhs, two rhs) {return (lhs.a<=rhs.a) && (lhs.b<=rhs.b);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	bool(*fn_pt)(two,two) = fncomp;
	std::set<two,bool(*)(two,two)> myset (fn_pt);
	std::set<two>::iterator it;
	std::pair<std::set<two>::iterator,bool> ret;
	
	ll n,x1,x2;
	cin>>n>>x1>>x2;
	
	ll l1[n],l2[n];
	ll m,c;
	
	two x;
	
	int count = 0;
	
	for(int i=0;i<n;i++)
	{
		cin>>m>>c;
		
		x.a = l1[i] = m*x1+c;
		x.b = l2[i] = m*x2+c;
		
		ret=myset.insert(x);
		
		if((*(ret.first)).a==l1[i] && (*(ret.first)).b==l2[i] && ret.second==false)
		{	
//			cout<<(*(ret.first)).a<<"  "<<(*(ret.first)).b<<endl;
//			cout<<l1[i]<<"  "<<l2[i]<<endl;
			count++;
		}		
	}
	
//	cout<<"there\n";
	
//	for(int i=0;i<n;i++)
//		cout<<l1[i]<<"  "<<l2[i]<<'\n';
	
//	sort(l1,l1+n);
//	sort(l2,l2+n);


//	cout<<"here\n";

//	for (it=myset.begin(); it!=myset.end(); it++)
//		cout <<(*it).a<<"  "<<(*it).b<<'\n';
	
	
/*	for(int i=0;i<n;i++)
	{
		x.a = l1[i];
		x.b = l2[i];
	
		it = myset.find(x);
		
		if(it==myset.end())
		{
			ans = true;
			break;
		}
	}*/
	
	bool ans = false;
	
//	cout<<"size "<<myset.size()<<" count "<<count<<'\n';
	
	if((myset.size()+count)!=n)
		ans = true;
	
	if(ans)
		cout<<"Yes\n";
	else
		cout<<"No\n";
		
	return 0;
}