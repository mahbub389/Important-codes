#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MX 1030000
int vis[MX],pr[MX];
char str[1002][1002];
queue <int>q;
int main()
{
    int i , j , t , u, v, u1, u2, u3, u4, l , r, n, m, x, y, a, b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d" , &n, &m);

        for(i=0; i<=n+1; i++)
            for(j=0; j<=m+1; j++)
            {
                str[i][j]='X';
            }

        for(i=1; i<=n; i++)
        {
            getchar();
            for(j=1; j<=m; j++)
            {
                scanf("%c",&str[i][j]);
                if(str[i][j]=='S')
                {
                    l=i;
                    r=j;
                }
                if(str[i][j]=='F')
                {
                    x=i;
                    y=j;
                }
            }
        }
         for(i=0; i<=n+1; i++)
        {

            for(j=0; j<=m+1; j++)
            {
                cout<<s[i][j];
            }
            cout<<endl;
        }
        q.push((l-1)*m+r);
        vis[(l-1)*m+r]=1;
       // while(q.size()!=0)
        {
            u=q.front();
            q.pop();
            u1=(u-1)/m+1;
            u3=u1;
            u2=u-(u1-1)*m;
            u4=u2;
            for(a=-1; i<=1; a++){
                for(b=-1; b<=1; b++)
                {

                    while(1)
                    {
                        v=(u3-1)*m+u4;
                        if(str[u3+a][u4+b]!='X')
                        {
                            u3+=a; u4+=b;
                        }
                        else if((u3!=u1 && u4!=u2)&&vis[v]!=1)
                        {
                            q.push(v);
                            vis[v]=1;
                            pr[v]=pr[u]+1;
                        }
                        else
                        {
                            u3=u1;
                            u4=u2;
                            break;
                        }
                        cout<<u3<<' '<<u4<<' '<<v<<endl;
                    }
                }
            }
        }
        for(i=0; i<=n*m; i++)
        {
            vis[i]=0;
            pr[i]=0;
        }
        if(pr[(x-1)*m+y]==0)
            printf("-1\n");
        else printf("%d\n",pr[(x-1)*m+y]);
    }

    return 0;
}

