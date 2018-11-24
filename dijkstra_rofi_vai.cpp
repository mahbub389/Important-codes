#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<utility>
using namespace std;

vector<long long int>v[100002];
vector<long long int>cost[100002];
long long int dist[100002],parent[100002];

class Node
{
public:
    long long int node_number,path;
    Node(long long int a, long long int b)
    {
        node_number=a;
        path=b;
    }
    Node()
    {

    }
};

bool operator<(Node A, Node B)
{
    return B.path<A.path;
}

long long int Dijkstra(long long int dest)
{
    priority_queue<Node>Q;
    long long int i,j,x;
    Node top;
    Q.push(Node(1,0));
    dist[1]=0;
    while(!Q.empty())
    {
        top=Q.top();
        Q.pop();
        x=top.node_number;
        if(x==dest)
            return dist[dest];
        for(i=0; i<v[x].size(); i++)
        {
            j=v[x][i];
            if(dist[x]+cost[x][i]<dist[j] || dist[j]==2147483647)
            {
                dist[j]=dist[x]+cost[x][i];
                parent[j]=x;
                Q.push(Node(j,dist[j]));
            }
        }
    }
    return -1;
}

int main()
{
    vector<long long int>out;
    long long int node,edge,node1,node2,i,j,k,ret,weight;
    while(scanf("%I64d %I64d",&node,&edge)!=EOF)
    {
        out.clear();
        for(i=0; i<100002; i++)
        {
            parent[i]=0;
            dist[i]=2147483647;
        }
        for(i=1; i<=edge; i++)
        {
            scanf("%I64d %I64d %I64d",&node1,&node2,&weight);
            v[node1].push_back(node2);
            v[node2].push_back(node1);
            cost[node1].push_back(weight);
            cost[node2].push_back(weight);
        }
        ret=Dijkstra(node);
        if(ret==-1)
        {
            printf("-1\n");
        }
        else
        {
            k=node;
            while(k)
            {
                out.push_back(k);
                k=parent[k];
            }
            for(i=out.size()-1; i>=0; i--)
            {
                printf("%I64d",out[i]);
                if(i)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
