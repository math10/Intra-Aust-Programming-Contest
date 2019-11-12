#include<bits/stdc++.h>
using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

string s;

int dp[1010][1010];
int func(int l, int r)
{
    if(l>=r)
    {
        return 0;
    }
    if(dp[l][r]!=-1) return dp[l][r];

    LL ret1=99999999;
    LL ret2=99999999;
    LL ret3=99999999;

    if(s[l]==s[r]) ret1 = func(l+1,r-1);
    ret2 = func(l+1,r)+1;
    ret3 = func(l,r-1)+1;

    return dp[l][r]=min3(ret1,ret2,ret3);

}


int main()
{
    FastRead
    int T;
    cin>>T;
    int c=1;
    while(T--)
    {
        memset(dp,-1,sizeof dp);
        cin>>s;
        cout<<"Case "<<c++<<": ";
        cout<<func(0,s.size()-1)<<"\n";

    }
}
