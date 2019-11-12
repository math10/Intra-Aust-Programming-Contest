#include<bits/stdc++.h>
using namespace std;

#define MX 1005

int C[MX][MX];
int m,n;
char X[MX],Y[MX];

void LCS()
{
    m = strlen(X);
    n = strlen(Y);
    for(int i = 1; i <= m; i++ )C[i][0] = 0;
    for(int j = 0; j <= n; j++ )C[0][j] = 0;

    for(int i = 1 ; i <= m; i++ )
    {
        for(int j = 1; j <= n; j++ )
        {
            if( X[i-1] == Y[j-1] )C[i][j] = C[i-1][j-1] + 1;
            else if( C[i-1][j] >= C[i][j-1] )C[i][j] = C[i-1][j];
            else C[i][j] = C[i][j-1];
        }
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        cin>>X;
        for(int i = strlen(X)-1; i >= 0; i-- )Y[strlen(X) - 1 - i] = X[i];
        LCS();
        printf("Case %d: %d\n",kase, strlen(X) - C[strlen(X)][strlen(Y)]);
        memset(Y, 0 , sizeof(Y));
    }
}
