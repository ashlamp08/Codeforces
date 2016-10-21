#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n,m,x;
    
    cin>>n>>m;
    
    long long max,lmin;
    
    max = -1;
    for(int i=0;i<n;i++)
    {
        lmin = 9999999999;
        for(int j=0;j<m;j++)
        {
            cin>>x;
            if(x<lmin)
                lmin = x;
        }
        if(lmin>max)
            max = lmin;
    }
    
    cout<<max<<'\n';
}