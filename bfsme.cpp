#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100];
bool visited[100] = {0};
int level[100];

void bfs(int source)
{
    queue <int> Q;
    Q.push(source);
    visited [source] = true;
    level [source] = 0;

    while( !Q.empty() ){
        int p=Q.front();
        Q.pop();

        for(int i = 0; i<adj[p].size(); i++){
            int m = adj[p][i];
            if(visited[m] == 0){
                visited[m] = 1;
                level[m] = level[p]+1;
                Q.push(m);
            }
        }
    }
}

int main()
{
    int vertex, edge, a, b, i, source, out;
    scanf("%d %d", &vertex, &edge);

    for(i=0; i<edge; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin>>source;
    bfs(source);
    while(cin>>out){
        cout<<level[out]<<endl;
    }
    return 0;
}
