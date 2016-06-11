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
const int mx = 1e6 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

const int MX = 10005;
vector<int > adj[MX],Radj[MX],order,Comp;
bool used[MX];
int newCompId[MX];
int N , M;
map<string, int>m;
int Max;
void dfs1(int u) {
    used[u] = true ;
    forstl(it,adj[u]) if( !used[ *it ] ) dfs1( *it );
    order.pb(u);
}

void dfs2(int u , int scc ){
    newCompId[u] = scc ;
    used[u] =  true ;
    Comp.pb(u);
    forstl(it,Radj[u]) if( !used[ *it ] ) dfs2( *it , scc );
}

void Reset(){
    For(i,N){
        adj[i].clear();
        Radj[i].clear();
    }
    memo(newCompId,0);
    memo(used,false);
    order.clear();
    m.clear();
    Max = 0;
}
int cc;
int get(string s){
    if(m.find(s) == m.end()) m[s] = ++cc;
    return m[s];
}

void Input(){
    cin >> N >> M ;
    cc = 0;
    rep(i,M){
        string x,y;
        cin >> x >> y;
        int u = get(x);
        int v = get(y);
        adj[u].pb(v);
        Radj[v].pb(u);
    }
}

void Zip(){
    reverse(all(order));
    int scc = 0 ;
    forstl(it,order){
        int v = *it ;
        if( !used[ v ] ){
            scc++;
            Comp.clear();
            dfs2(v,scc);
            Max = max(Max,(int)Comp.size());
        }
    }
}

void Kosaraju(){
    For(i,N) if( !used[i] ) dfs1(i);
    memo(used,false);
    Zip();
}

int main(){
    #ifdef Sanim
        freopen("in.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = II;
    For(cs,t){
        Input();
        Kosaraju();
        bool ans = Max > (N/2);
        if( ans ) cout << "Fight the white walkers." << endl;
        else cout << "Doomed." << endl;
        Reset();
    }
}
