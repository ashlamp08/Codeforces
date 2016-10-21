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
    
    int arr[N][2];
    
    for(int i=0;i<N;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    
    if(N==1)
    {
        cout<<-1<<'\n';
    }
    else if(N==2)
    {
        if((arr[0][0] == arr[1][0] || (arr[0][1] == arr[1][1])))
        {   cout<<-1<<'\n';}
        else
        {
            cout<<abso(arr[0][0] - arr[1][0])*abso(arr[0][1] - arr[1][1])<<'\n';
        }
    }
    else if(N==3)
    {
        int a = max(arr[0][0],arr[1][0]);
        a = max(a,arr[2][0]);
        
        int b = min(arr[0][0],arr[1][0]);
        b = min(b,arr[2][0]);   
        
        int c = max(arr[0][1],arr[1][1]);
        c = max(c,arr[2][1]);
        
        int d = min(arr[0][1],arr[1][1]);
        d = min(d,arr[2][1]);
        
        cout<<(a-b)*(c-d)<<'\n';    
    }
    else
    {
        int a = max(arr[0][0],arr[1][0]);
        a = max(a,arr[2][0]);
        a = max(a,arr[3][0]);
        
        int b = min(arr[0][0],arr[1][0]);
        b = min(b,arr[2][0]);
        b = min(b,arr[3][0]);   
        
        int c = max(arr[0][1],arr[1][1]);
        c = max(c,arr[2][1]);
        c = max(c,arr[3][1]);
        
        int d = min(arr[0][1],arr[1][1]);
        d = min(d,arr[2][1]);
        d = min(d,arr[3][1]);
        
        cout<<(a-b)*(c-d)<<'\n';
    }   
    
    return 0;
}