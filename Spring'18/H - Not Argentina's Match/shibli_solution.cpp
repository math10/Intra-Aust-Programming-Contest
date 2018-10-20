#include<bits/stdc++.h>
using namespace std;

#define MX 105

int DP[MX][1010],weight[MX],price[MX];
int n,capacity;

void init()
{
    memset(DP,-1,sizeof(DP));
}

int knapsack(int i, int w)
{
    if( i == n+1 )
        return 0;

    if( DP[i][w] != -1 )
        return DP[i][w];

    int value1,value2;

    value1 = value2 = 0;

    if( w + weight[i] <= capacity )
    {
        value1 = price[i] + knapsack(i+1,w+weight[i]);
    }

    value2 = knapsack(i+1,w);

    DP[i][w] = max(value1,value2);
    return DP[i][w];
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d %d",&n,&capacity);
        init();

        for(int i = 1; i <= n; i++ )
            scanf("%d %d",&weight[i],&price[i]);

        printf("%d\n",knapsack(1,0));
    }
}

