
/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
handle: math10
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
#define pii pair<int64 ,int64 >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'|c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<"    ";
        return *this;
    }
} dbg;
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 240 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

const int MX = 1e6 + 7 ;
int divisors[MX] ;
void preGen(){
    const int SQ = sqrt(MX) + 1 ;
    int isPrime[SQ+7];
    memset(isPrime,1,sizeof isPrime);
    memset(divisors,0,sizeof divisors);
    for( int i = 2 , j ; i < SQ ;i++) {
        if( isPrime[i]) {
            for ( j = i * i ; j < SQ ; j += i) {
                isPrime[j] = 0;
                divisors[j]= i ;
            }
            for ( ; j <= MX - 7 ; j += i ) divisors[j] = i ;
        }
    }
    //Applying the formula
    //Divisor(N)=Divisors(N/p^f(N,p))*(f(N,p)+1)
    divisors[1] = 1 ;
    for(int i = 2 ; i < MX ; i++ ) {
        if ( divisors[i] == 0 ) divisors[i] = 2 ;
        else {
           int k = i / divisors[i] , cnt = 2 ;
           while ( k % divisors[i] == 0 ) k /= divisors[i] , cnt++ ;
           divisors[i] = divisors[k] * cnt ;
        }
    }
}

struct node {
    int lf, rt, id;
    node(){}
    node(int _lf,int _rt, int _id) {
        lf = _lf;
        rt = _rt;
        id = _id;
    }
};
vector<pii >v[mx];
vector<node>qur[mx];

bool cmp(node a, node b){
    return (a.rt<b.rt ||(a.rt==b.rt &&a.lf<b.lf));
}

int A[MX<<2],pre[MX], ans[MX];
void update(int lf,int rt,int idx,int x,int val){
    if(lf == x && rt == x){
        A[idx] += val;
        return;
    }
    int mid = (lf+rt)>>1;
    if(x<=mid)update(lf,mid,idx*2,x,val);
    else update(mid+1,rt,idx*2+1,x,val);
    A[idx] = A[idx*2] + A[idx*2+1];
}

int query(int lf,int rt,int idx,int x,int y){
    if(lf>=x && rt<=y) return A[idx];
    int mid = (lf+rt)>>1,ret = 0;
    if(x<=mid) ret += query(lf,mid,idx*2,x,y);
    if(mid<y) ret += query(mid+1,rt,idx*2+1,x,y);

    return ret;
}

int main(){
    #ifdef Sanim
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    preGen();
    int t = II;
    For(cs,t){
        rep(i,mx) v[i].clear();
        int n = II;
        rep(i,n){
            int x = II;
            v[divisors[x]].pb(pii(x,i+1));
        }
        int q = II;
        rep(i,q){
            int L = II, R = II, D = II;
            qur[D].pb(node(L,R,i));
        }
        rep(i,mx)sort(all(qur[i]), cmp);
        memo(pre,-1);
        rep(i,mx){
            int sz = qur[i].size();
            int cnt = 0;
            for(auto x : v[i]) {
                while(cnt < sz && x.ss > qur[i][cnt].rt) {
                    ans[qur[i][cnt].id] = query(1,n,1,qur[i][cnt].lf, qur[i][cnt].rt);
                    ++cnt;
                }
                if(pre[x.ff] != -1){
                    update(1,n,1,pre[x.ff],-1);
                }
                update(1,n,1,x.ss,1);
                pre[x.ff] = x.ss;
                while(cnt < sz && x.ss == qur[i][cnt].rt) {
                    ans[qur[i][cnt].id] = query(1,n,1,qur[i][cnt].lf, qur[i][cnt].rt);
                    ++cnt;
                }
            }

            while(cnt < sz) {
                ans[qur[i][cnt].id] = query(1,n,1,qur[i][cnt].lf, qur[i][cnt].rt);
                ++cnt;
            }

            for(auto x : v[i]) {
                if(pre[x.ff] == -1) continue;
                update(1,n,1,pre[x.ff],-1);
                pre[x.ff] = -1;
            }
            qur[i].clear();
            v[i].clear();
        }

        OC;
        NL;
        rep(i,q){
            printf("%d\n",ans[i]);
        }

    }
}

