/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define eb emplace_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "["; forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i; cerr << "]" << endl;
}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e3 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}


int weight[110];
int n,M;
int dp[110][1010];
int flag[110][1010];
int take[110];
int Knapsack(int maxWeight){

        int iter,w;
        for(iter=0;iter<=maxWeight;iter++){
            dp[0][iter]=0;
            flag[0][iter] = -1;
        }

        for(iter=0;iter<=n;iter++){
            dp[iter][0]=0;
            flag[iter][0] = -1;
        }

        int wh = 0,it = 0;
        for(iter=1;iter<=n;iter++){
            if(take[iter]) {
                for(w=0;w<=maxWeight;w++){
                    dp[iter][w] = dp[iter-1][w];
                    flag[iter][w] = flag[iter-1][w];
                }
                continue;
            }
            it = iter;
            for(w=0;w<=maxWeight;w++){
                dp[iter][w] = dp[iter-1][w];
                flag[iter][w] = flag[iter-1][w];
                if(w-weight[iter] >=0){
                    if(dp[iter][w] < dp[iter-1][w-weight[iter]]+weight[iter]){
                        dp[iter][w] = dp[iter-1][w-weight[iter]]+weight[iter];
                        flag[iter][w] = iter;
                    }
                }
            }

        }
        if(it == 0) return 0;
        int ans = dp[it][maxWeight];
        wh = ans;
        while(wh > 0){
            it = flag[it][wh];
            take[it] = 1;
            wh -= weight[it];
            it--;
        }
        return ans;
}

int call(int mid){
    memo(take,0);
    rep(i,M)Knapsack(mid);
    For(i,n)if(!take[i]) return 0;
    return 1;
}

int main() {
#ifdef Sanim
    //geting WA check int64 & int64u
    freopen ("inputd.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        n = II, M = II;

        For(i,n){
            weight[i] = II;
        }

        int64 low = 1,high = 1000,ans = -1;
        while(low<=high){
            int64 mid = (low+high)>>1;
            if(call(mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        OC;
        cout << " " << ans << endl;
    }
}
