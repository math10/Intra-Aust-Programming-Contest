
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define Max(a,b) ((a>=b)? a : b)
#define Min(a,b) ((a<=b)? a : b)
#define pb push_back
#define MOD 1000000007
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define MAX 32001
#define SZ 5
//typedef __int128 bigll;
ll dp[505];
ll catalan(ll n)
{
    if(n<=1)return dp[n]=1;
    if(dp[n]!=0)return dp[n];
    ll sum=0;
    for(int i=0;i<n;i++)
        sum+=(catalan(i)*catalan(n-i-1))%MOD;
    return dp[n]=sum%MOD;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //FILE*f=freopen("input.txt","r",stdin);
    //FILE*o=freopen("output.txt","w",stdout);
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",catalan(n));
    }

    //fclose(f);
    //fclose(o);

    return 0;
}
