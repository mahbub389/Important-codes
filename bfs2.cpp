void bfs(int n)
{
    visited[s]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        int l=edges[u].size();
        for(i=0;i<l;i++)
        {
            v=edges[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
}
