#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define sz 100005
typedef long long LL;
typedef pair<LL , LL> pi;

vector<pi> vec[sz];
LL dist[sz] , path[sz];

void dijkstra()
{
    memset(dist , -1 , sizeof(dist));
    priority_queue<pi, vector<pi> ,greater<pi> > pq;
    pq.push(mp(0,1));
    dist[1] = 0;

    while(!pq.empty()){
        LL u = pq.top().second;
        pq.pop();

        LL len = vec[u].size();

        for(int i = 0 ; i < len ; i++){

            LL w = vec[u][i].first;
            LL v = vec[u][i].second;
            if(dist[u]+v < dist[w] || dist[w]==-1){
                dist[w] = dist[u] + v;
                path[w] = u;
                pq.push(mp(dist[w] , w));
            }
        }
    }
}

void print(int n)
{
    if(n == 1){
        printf("%d " , n);
        return;
    }
    print(path[n]);
    printf("%d ",n);

}

int main()
{
    int n , m , i , u , v , w ;
    scanf("%d %d" ,&n ,&m);
    for(i = 0 ; i < m ; i++){
        scanf("%d %d %d", &u ,&v, &w);
        vec[u].push_back(mp(v,w));
        vec[v].push_back(mp(u,w));
    }
    dijkstra();
    if(dist[n] == -1)
        printf("-1\n");
    else{
        print(n);
        printf("\n");
    }
    return 0;
}

