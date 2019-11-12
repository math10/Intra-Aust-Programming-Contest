
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

const int N=501;
vector<int>V;
int n,k;
int dp[N];

bool call(int val)
{
    if(dp[val]!=-1) return dp[val];
    bool f=false;
    for(int i=0;i<V.size() and V[i]<=val;i++) {
        if(call(val-V[i]) == 0){
            f = 1;break;
        }
    }
    return dp[val] = f;
}

int main()
{
    FastRead
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        V.clear();
        FOR(i,1,n) if(__gcd(i,k)==1 and (i & k)) V.pb(i);
        MEM(dp,-1);
        bool f=call(n);
        if(f) cout << "Turja\n";
        else cout << "Akash\n";
    }
}
