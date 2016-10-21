#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int defective(string a)
{
    int ln = a.size();
    int c = 0;
    for(int i=0;i<ln;i++)
    {
        if(a[i]=='1')
        {
            c++;
            if(c>1)
                return 1;
        }
        else if(a[i]!='0')
        {
            return 1;
        }
    }
    return 0;
}
            
            

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    string a;
    string p;
    int count=0;
    bool flag = false; 
    
    int flop = 0;
    
    while(n--)
    {
        cin>>a;
        
        if(a.size()==1 && a[0]=='0')
        {
            flag = true;
            break;
        }
                    
        if(defective(a))
        {
            p = a;
            flop++;
        }
        else
        {
            count+=(a.size() -1);
        }
    }
    
    if(flag)
        cout<<0<<'\n';
    else
    {
    if(!flop)
        cout<<"1";
    else
        cout<<p;
    
    for(int i=0;i<count;i++)
        cout<<'0';
    cout<<'\n';
    }
    return 0;
}