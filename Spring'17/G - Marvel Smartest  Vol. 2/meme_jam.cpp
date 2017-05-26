#include<bits/stdc++.h>
#define MOD 1000000007
#define MAX 100000
using namespace std;

int dp[MAX+7];


void init()
{
    dp[0]=dp[1]=1; //C_(1)=C_(0)=1

    for(int i=2; i<MAX+7; i++)
        dp[i]=(dp[i-2]+dp[i-1])%MOD;

    /*  for(int i=0;i<10;i++)
          printf("%d\n",dp[i]);
    */
}

int main()
{
    init();
    int res,cases,inp,n;
    scanf("%d",&cases);
    //printf("%d",cases);
    while(cases--)
    {
        scanf("%d",&inp);
        n=inp;
        res=dp[n-2];
        printf("%d\n",res);
    }
    return 0;
}
