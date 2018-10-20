#include<bits/stdc++.h>
using namespace std;

int wt[110][110];
int dp[110][110][505];
int n;

void rec(int srt,int u,int w)
{
    int &ret=dp[srt][u][w];
    if(ret!=-1) return ;
    ret=1;
    for(int i=1; i<=n; i++)
    {
        if(u==i) continue;
        if(wt[u][i]==0) continue;
        if(w+wt[u][i]>500) continue;
        rec(srt,i,w+wt[u][i]);
    }
}


int main()
{
    int u,v,w;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) scanf("%d",&wt[i][j]);
    }
    memset(dp,-1,sizeof dp);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&u,&v,&w);
        rec(u,u,0);
        int f=-1;
        for(int i=w; i>=0; i--)
        {
            if(dp[u][v][i]==1)
            {
                f=i;
                break;
            }
        }
        printf("%d\n",f);
    }

}
