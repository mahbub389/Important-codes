#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
int i,vis[1000];
int parent[1000];
bool cycle = false;

void dfs(int s)
{
    vis[s] = 1;
    for(i = 0 ; i < adj[s].size() ; i++)
    {
        int x = adj[s][i];
        if(vis[x] == 0){
            parent[x] = s;
            dfs(x);
        }
        if(vis[x] == 1){
            if(parent[s] != x)
                cycle = true;
        }
    }
}

int main()
{
    int n , u , v ,s;
    cin >>n;

    for(i = 0 ; i < n ; i++){
        cin >> u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(cin >> s){
        cycle = false;
        dfs(s);
        if(cycle) cout<<"Cycle exists\n";

        else cout<<"Cycle doesn't exist\n";
    }

    return 0;
}
