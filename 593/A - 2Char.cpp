#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define MAX 1000009
#define ll long long

int maxim(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin>>n;
    
    string s[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    
    ll max = 0;
    
    bool a;
    
    for(char i='a';i<='z';i++)
    {
        for(char j='a';j<='z';j++)
        {   
            int sum = 0;        
            for(int k=0;k<n;k++)
            {
                a = false;
                for(unsigned l = 0;l<s[k].length() && (!a);l++)
                    a = (s[k][l]!=i)&&(s[k][l]!=j);
                if(!a)
                    sum = sum + s[k].length();  
            }
            max = maxim(max,sum);
        }
    }
    
    cout<<max<<'\n';
    
    return 0;
}