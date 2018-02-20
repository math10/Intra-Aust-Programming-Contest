// Calculate nCr
// Pascal's Triangle Method
#include<bits/stdc++.h>
using namespace std;

#define mx 60
typedef long long lli;

lli dp[mx+10][mx+10] ;
void nCr()
{
    for(int i=0;i<=mx;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i) dp[i][j] = 1 ;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ;
        }
    }
}

int main()
{
    nCr();
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        int nn,m , n , r;
        scanf("%d %d",&nn,&m);
        n = nn + m - 2;
        r = m - 1;
        printf("Case %d: %lld\n",kase,dp[n][r]);

    }
}

