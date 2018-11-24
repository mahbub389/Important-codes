#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))

typedef long long int          LL;
typedef unsigned long long int LLU;
typedef vector<int>            vi;
typedef pair<int,int>          pii;

#define mx 100000

vector<pii>adj[mx+1];
int parent[mx+1],n,m,u,v,w,i;
LL dist[mx+1];
vi out;

void dijkstra()
{
    mem(parent,-1);
    mem(dist,-1);
    priority_queue<pii , vector<pii> , greater<pii> >Q;
    Q.push(mp(0,1));
    dist[1]=0;
    while(Q.size())
    {
        u=Q.top().second;
        Q.pop();
        for(i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i].first;///node
            w=adj[u][i].second;///cost
            if(dist[v]==-1 or dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
                Q.push(mp(dist[v],v));
            }
        }
    }
}

void print()
{
    u=n;
    while(u!=-1)
    {
        out.pb(u);
        u=parent[u];
    }
    for(i=out.size()-1; i>=0; i--) printf("%d ",out[i]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    dijkstra();
    if(dist[n]==-1) printf("-1");
    else print();
    return 0;
}
