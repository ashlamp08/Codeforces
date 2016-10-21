#include<iostream>
#include<utility>
#include<string>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<set>

using namespace std;

int n,m;
char str[1009][1009];
bool visited[1009][1009];
int component[1009][1009];
int c = 1;

long long dfs(int i, int j)
{
    if(i==-1 || j==-1)
        return 0;
    if(i==n || j==m)
        return 0;
        
    if(visited[i][j]==true)
        return 0;
    
    if(str[i][j]=='*')
    {
        component[i][j] = 0;
        return 0;
    }
    
    component[i][j] = c;
    visited[i][j] = true;
    return 1 + dfs(i,j+1) + dfs(i,j-1) + dfs(i+1,j) + dfs(i-1,j);
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    long long comp[n*m];
    
    memset(comp,0,n*m*sizeof(int));
    memset(visited,false,1009*1009*sizeof(bool)); 
    memset(component,0,1009*1009*sizeof(int)); 
    
    comp[0] = 0;
    
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && str[i][j]=='.')
            {
                comp[c] = dfs(i,j);
                c++;
            }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='*')
            {
                std::set<int> myset;
                std::set<int>::iterator it;
                if(j!=m && str[i][j+1]=='.')
                    myset.insert(component[i][j+1]);
                if(j!=0 && str[i][j-1]=='.')
                    myset.insert(component[i][j-1]);
                if(i!=n && str[i+1][j]=='.')
                    myset.insert(component[i+1][j]);
                if(i!=0 && str[i-1][j]=='.')
                    myset.insert(component[i-1][j]);    
                
                long long sum = 1;
                for (it=myset.begin(); it!=myset.end(); ++it)
                    sum += (comp[*it]);
                
                str[i][j] = '0' + (sum%10);
            }
        }
    }
            
    for(int i=0;i<n;i++)
    {
        cout<<str[i]<<'\n';
    }       
        
    
    return 0;
}