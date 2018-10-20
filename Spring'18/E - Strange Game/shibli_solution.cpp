#include<bits/stdc++.h>
using namespace std;

#define MX 10010
typedef long long lli;
int arr[MX];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt", "w", stdout);
    int t,n;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);

        lli sum;
        sum =  0;
        for(int i = 0; i < n; i++ )
        {
            scanf("%d",&arr[i]);
            sum += arr[i];
        }

        double ans = 1.00*sum/n;

        lli t1 = (long long)floor(ans);
        lli t2 = (long long)ceil(ans);

        lli sum2,res;
        sum2 = res = 0;
        for(int i = 0; i < n; i++ )
        {
            lli sum2 = arr[i] - t1;
            sum2 *= sum2;
            res += sum2;
        }

        lli sum3,res1;
        sum3 = res1 = 0;
        for(int i = 0; i < n; i++ )
        {
            lli sum3 = arr[i] - t2;
            sum3 *= sum3;
            res1 += sum3;
        }

        lli mn = min(res,res1);
        if( mn == res )printf("Case %d: %lld %lld\n",kase,t1,res);
        else printf("Case %d: %lld %lld\n",kase,t2,res1);
    }
}

