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
#define IUL ({ int64u a; read(a);  a;})
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
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

const int max_child = 30;
int get_id(int id){
    return id- 'a';
}

struct node{
    int val;
    int next[max_child];
    node(){
        val=0;
        rep(i,max_child)
            next[i]=-1;
    }
}trie[mx];
int cnt = 0;
void _insert(string str){
    int node_id = 0;
    int len = str.size();
    rep(i,len){
        if(trie[node_id].next[get_id(str[i])]==-1){
            trie[node_id].next[get_id(str[i])] = ++cnt;
        }
        node_id = trie[node_id].next[get_id(str[i])];
    }
    trie[node_id].val++;
}

int traverse(node &p){
    int tmp = 0;
    rep(i,max_child){
        if(p.next[i]!=-1){
            tmp ^= traverse(trie[p.next[i]]);
        }
        p.next[i] = -1;
    }
    return tmp+1;
}

char ch[mx];

int main(){
    #ifdef Sanim
        freopen("input04.txt", "r", stdin);
       freopen("output04.txt", "w", stdout);
    #endif

    int t = II;
    For(cs,t){
        int n = II;
        cnt = 0;
        rep(i,n){
            scanf("%s", ch);
            _insert(ch);
        }
        int ans = 0;
        node &p = trie[0];
        rep(i,max_child){
            if(p.next[i] != -1){
                ans ^= traverse(trie[p.next[i]]);
            }
            p.next[i] = -1;
        }

        //rep(i,mx)rep(j,max_child){trie[i].next[j] = -1;}
        OC;
        printf(" %s\n", ans ? "Arnab" : "Mahir");
    }
}

