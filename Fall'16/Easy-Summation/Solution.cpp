#include <bits/stdc++.h>
using namespace std;

long long r,a,b,d;

long long mulmod(long long x,long long y,long long z)
{
    if(y==0||x==0) return 0;
    else if(y%2) return ((x%z)+mulmod(x,y-1,z))%z;
    else return (2*mulmod(x,y/2,z))%z;
}

long long lcm(long long x,long long y)
{
    x/=__gcd(x,y);
    if(x>r/y) return r+1 ;
    return x*y ;
}

long long series_sum(long long _a,long long n,long long mod)
{
    long long lf = mulmod(_a,n,mod);
    long long ri ;
    if(n%2==0) ri = mulmod(n/2,n-1,mod);
    else ri = mulmod(n,(n-1)/2,mod);
    ri = mulmod(ri,_a,mod);
    return (ri+lf)%mod ;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t ;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lld%lld%lld%lld",&r,&a,&b,&d);
        long long x = series_sum(a,r/a,d);
        long long y = series_sum(b,r/b,d);
        long long z = series_sum(lcm(a,b),r/lcm(a,b),d);
        long long ans = (x+y)%d;
        ans = (ans-z)%d;
        ans = (ans+d)%d;
        printf("%lld\n",ans);
    }
    return 0;
}
