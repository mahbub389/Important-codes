#include<bits/stdc++.h>
using namespace std;

#define sz 100005

struct mystruct
{
    int vertex;
    int cost;
    mystruct(const int& weight ,const int& node){
        vertex = node;
        cost = weight;
    }
    bool operator < (const mystruct& A)const{
        return cost < A.cost;
    }
};
vector<mystruct> vec[sz];
long long dist[sz] ;
int parent[sz];

void dijkstra()
{
    memset(dist , -1 , sizeof(dist));
    memset(parent , -1 , sizeof(parent));
    priority_queue<mystruct> pq;
    pq.push(mystruct(0 , 1));
    dist[1] = 0;

    while(!pq.empty()){
        int u = pq.top().vertex;
        pq.pop();

        int len = vec[u].size();

        for(int i = 0 ; i < len ; i++){

            int w = vec[u][i].vertex;
            int v = vec[u][i].cost;
            ///cout<<w<<" "<<v<<endl;
            if(dist[u]+v < dist[w] || dist[w]==-1){
                dist[w] = dist[u] + v;
                parent[w] = u;
                pq.push(mystruct(dist[w] , w));
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
    print(parent[n]);
    printf("%d ",n);

}

int main()
{
    int n , m , i , u , v , w;
    cin >> n >> m;
    for(i = 0 ; i < m ; i++){
        cin>>u>>v>>w;
        vec[u].push_back(mystruct(w,v));
        vec[v].push_back(mystruct(w,u));
    }
    dijkstra();
    if(dist[n] == -1)
        cout<<"-1\n";
    else{
        print(n);
    }
    return 0;
}
