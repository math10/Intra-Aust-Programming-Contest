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

int n,m,ans;
string str[100];

bitset<100>g[16];
void rec(int pos,bitset<100>b,int took)
{
    if(pos == m){
//        cout << "here " << b << " " << b.count() << "\n";
        if(b.count() == n)ans = min(ans,took);
        return;
    }
    rec(pos + 1,b,took);
    rec(pos + 1,b | g[pos],took + 1);
}

int main()
{
    FastRead
    int t,tc=0;
    cin >> t;
    while(t--)
    {
        for(int i = 0;i < 16;i++)g[i] = g[i].reset();
        cin >> n;
        REP(i,n) cin >> str[i];
        m=str[0].size();
        ans=1e9;
        for(int j = 0;j < m;j++){
            for(int i = 0;i < n;i++){
                if(str[i][j] == 'Y')g[j].set(i,1);
            }
//            cout << g[j] << "\n";
        }
        bitset<100>b;
        rec(0,b,0);
        cout << "Case " << ++tc << ": " << ans << '\n';
    }
}
