#include<bits/stdc++.h>
#define MOD 1000000007
#define MAX 100000
using namespace std;

int dp[MAX+7];

void init()
{
    dp[0]=dp[1]=1; //C_(1)=C_(0)=1

    for(int i=2;i<MAX+7;i++)
        dp[i]=(dp[i-2]+dp[i-2])%MOD;


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
        //printf("%d\n",inp);
        if(n==1)res=5;
        else
        {
            res=(dp[n-1]+dp[n-1])%MOD;
            res+=((dp[n-2]+dp[n-2])%MOD);
            res+=2;
            res%=MOD;
        }
        printf("%d\n",res);
    }
return 0;
}
