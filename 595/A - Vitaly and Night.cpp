#include<iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    int a,b,count;
    
    count = 0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a>>b;
            
            if(a||b)
                count++;
        }
    }
    
    cout<<count<<'\n';
    
    return 0;
}