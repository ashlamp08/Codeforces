#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    
    cin>>s;
    
    int n,m;
    
    n = s.length();

    int cumm[100005] = {0};
    
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
            cumm[i] = 1;
    }
    
    for(int i=1;i<n;i++)
        cumm[i] += cumm[i-1];
        
    cin>>m;
    
    while(m--)
    {
        int l,r;
        
        cin>>l>>r;
        
        if(l!=1)
            cout<<cumm[r-2]-cumm[l-2]<<'\n';
        else
            cout<<cumm[r-2]<<'\n';
    }
    
    return 0;
}