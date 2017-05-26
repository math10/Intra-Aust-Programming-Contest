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
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
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
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

const int MAX_NODE = 100000;
const int MAX_EDGE = 100000;
const int MAX_COST = 100000000;

struct edge{
    int u,v,w;
    edge( int a ,int b, int c){
        u = a , v = b , w = c;
    }
    edge(){};
};

bool operator < ( edge a ,edge b){  return a.w > b.w ; }

int prev[mx];

int Parent(int i){
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

int isUnion(int a,int b){
    return Parent(a)==Parent(b);
}

void makeUnion(int a,int b ){
    prev[Parent(a)] = Parent(b);
}

int64 MST(int n , edge *x , int e ){
  sort(x,x+e);
  rep(i,n+2) prev[i] = i ;
  int64 mst = 0 , spanning_edges = 0 ;
  rep(i,e){
        if(!isUnion(x[i].u,x[i].v)){
                makeUnion(x[i].u,x[i].v);
                mst += x[i].w;
                spanning_edges ++ ;
         }
   }

   assert(spanning_edges == n - 1 );
   return mst ;
}

edge ed[mx];

int main() {
#ifdef Sanim
    freopen ("in2.txt", "r", stdin);
    freopen ("output2.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t) {
        int n = II,m = II;
        __(n,m, MAX_NODE, MAX_EDGE)
        assert(n > 2 && n <= MAX_NODE && m >= n && m <= MAX_EDGE);
        rep(i,m) {
            ed[i].u = II, ed[i].v = II, ed[i].w = II;
            //__(ed[i].u , ed[i].v,n,m)
            assert(ed[i].u >= 1 && ed[i].u <= n);
            assert(ed[i].v >= 1 && ed[i].v <= n);
            assert(ed[i].u != ed[i].v);
            assert(ed[i].w >= 1 && ed[i].w<= MAX_COST);
        }
        int64 ans = MST(n, ed, m);
        printf("Case %d: %d %lld\n",cs, n-1, ans);
    }
}
