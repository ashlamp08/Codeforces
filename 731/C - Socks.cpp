// $-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$ //
//                                      ashlamps08                                         //
// $-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$ //

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<ld,ld>
#define sf(a) scanf("%d",&a)
#define pf(a) scanf("%d",a)

const int inf = 1e9 + 7;

const int VSIZE = 200005;
const int ESIZE = 200005;

vector<int> G[VSIZE];
pii edge[ESIZE];

int col[200005];

int visited[200005]={0};

map<int,int> colmap;

int dfs(int u)
{
    visited[u] = 1;
    colmap[col[u]]++;
    int res = 0;
    for(auto e: G[u])
    {
        int v = edge[e].first + edge[e].second - u;
        if(!visited[v]){
            res+= 1 + dfs(v);
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n,m,k;

    cin>>n>>m>>k;

    for(int i=0;i<n;i++)
        cin>>col[i];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        a--,b--;

        G[a].push_back(i);
        G[b].push_back(i);

        edge[i] = {a,b};
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        if(!visited[i])
        {
            colmap.clear();
            int x = dfs(i);
            x++;
            //cout<<x<<endl;
            int y = -1;
            for(auto z: colmap)
            {
                //cerr<<z.second<<endl;
                y = max(y,z.second);
            }
            ans += x - y;
        }
    }

    cout<<ans;

    return 0;
}