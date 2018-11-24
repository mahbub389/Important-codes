#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000000000000ll

int V, E, s;
vector <vii> adjList;
vi path;
vector <ll> dist;

void IO()
{
	freopen("input.txt", "r", stdin);
	///freopen("output.txt", "w", stdout);
}

void printPath(int u)
{
    if (u == s)
    {
        printf("%d", u);
        return;
    }

    printPath(path[u]);
    printf(" %d", u);
}

void storeGraph()
{
    scanf("%d%d",&V, &E);

    adjList.assign(V+1,vii());  ///1-based index

    for(int i=0; i<E; i++)
    {

        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);

        adjList[a].push_back(ii(w,b));
        adjList[b].push_back(ii(w,a));

    }
}

void dijkstra()
{
    priority_queue< ii, vector<ii>, greater<ii> > pq;

    dist.assign(V+1,INF);   ///1-based index
    path.assign(V+1,-1);    ///1-based index

    s=1;
    dist[s]=0;
    pq.push(ii(0, s));

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d>dist[u]) continue;

        int loop = adjList[u].size();

        for(int i=0; i<loop; i++)
        {
            int w = adjList[u][i].first;
            int v = adjList[u][i].second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push(ii(dist[v],v));
            }

        }
    }
}
int main()
{
    storeGraph();
    dijkstra();

    if(dist[V]==INF)
		printf("-1\n");
	else
    {
        printPath(V);
        printf("\n");
    }
    return 0;
}

