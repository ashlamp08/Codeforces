#include<iostream>
#include<utility>
#include<string>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

template <class t1, class t2>
class Graph
{
    public:
    vector< pair<t1,t2> > node[100005];
    bool visited[100005];
    stack<int> stk;
    
    void init()
    {
        memset(visited,false,100005);
        while(!stk.empty())
            stk.pop();
    }
    
    void add_edge(int u, int v, int w)
    {
        pair<t1,t2> p;
        p = make_pair(v,w);
        node[u].push_back(p);
    }
    
    void show_graph()
    { 
        for(int i=0;i<10;i++)
        {
            int size = node[i].size();
            cout<<i<<" -> ";
            for(int j=0;j<size;j++)
                cout<<"("<<node[i][j].first<<','<<node[i][j].second<<")"<<" -> ";
            cout<<"x\n";
        }
    }
};  
long long dp[100005];
Graph<int,int> G;
long long tailspine(int i)
{   
    if(dp[i]!=-1)
            return dp[i];
    
    dp[i] = 1;
    
    long long size;
    
    size = G.node[i].size();
    
    for(int j=0;j<size;j++)
    {
        if(G.node[i][j].first < i)
        {
    
            dp[i] = max(dp[i],1 + tailspine(G.node[i][j].first));
        }
            
    }
    
    return dp[i];
}   


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long N,M,x,y;
    long long max,banana;
    
        cin>>N>>M;
        memset(dp,-1,100005*sizeof(long long));
        
        for(int i=1;i<=M;i++)
        {   
            cin>>x>>y;
            G.add_edge(x,y,0);
            G.add_edge(y,x,0);
        }
        
        max = -1;
            
    //  G.show_graph(); 
            
        for(int i=1;i<=N;i++)
        {
        
            banana = tailspine(i)*(long long)G.node[i].size();
            if(banana>max)
                max = banana;
        }
        
        cout<<max<<'\n';

    return 0;
}