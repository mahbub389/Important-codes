#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define mx 100002
using namespace std;
vector<long long>graph[mx],cost[mx];
struct node
{
    int u,w;
    node(int a,int b)
    {
        u=a;
        w=b;
    }
    bool operator < ( const node& p ) const
    {
        return w > p.w;
    }
};
long long dist[mx],parent[mx];
int dijkstra(int n)
{
    memset(dist,-1,sizeof(dist));
    memset(parent,-1,sizeof(parent));
    priority_queue<node>Q;
    Q.push(node(1,0));
    dist[1]=0;
    while(!Q.empty())
    {
        node top=Q.top();
        Q.pop();
        long long u=top.u;

        if(u==n) return dist[n];
        for(int i=0; i<(int)graph[u].size(); i++)
        {
            long long v=graph[u][i];
            if(dist[u]+cost[u][i]<dist[v]||dist[v]==-1)
            {
                dist[v]=dist[u]+cost[u][i];
                parent[v]=u;
                Q.push(node(v,dist[v]));
            }
        }
    }
    return -1;
}
int main()
{
    int n,e;
    scanf("%d%d",&n,&e);

    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

    }
    long long ret=dijkstra(n);
    if(ret==-1) printf("-1\n");
    else
    {
        int u=n;
        vector<long long>out;
        while(u!=-1)
        {
            out.push_back(u);

            u=parent[u];

        }
        reverse(out.begin(),out.end());
        for(int i=0; i<(int)out.size(); i++)
            cout<<out[i]<<" ";
        puts("");

    }

    return 0;
}
