#include<iostream>

using namespace std;

typedef long long ll;

int abso(int a)
{
        if(a<0)
            return -a;
        else
            return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    
    cin>>N;
    
    ll arr[N];
    
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    ll count = abso(arr[0]);
    
    for(int i=1;i<N;i++)
    {
        count+=abso(arr[i]-arr[i-1]);
    }
    
    cout<<count<<'\n';
    
    return 0;
}