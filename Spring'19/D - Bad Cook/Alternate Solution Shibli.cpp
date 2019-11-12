#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 2002
#define MOD 1000000007
lli fact[MX];

void pre_calculate()
{
    fact[0] = 1;
    for(int i = 1; i <= MX; i++)fact[i] = (fact[i-1] * i)%MOD;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pre_calculate();
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        int n;
        scanf("%d", &n);
        int a = n/2;
        int b = a + 1;
        lli ans = (fact[a] * fact[b])%MOD;
        printf("%lld\n", ((ans-1)<0)?((ans-1)+MOD):(ans-1));
    }
}

