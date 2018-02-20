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
const int mx = 1e6 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int64 arr[mx];

double getMedian(int lf,int rt){
    int len = rt - lf + 1;
    if(len%2){
        return arr[lf + (len/2)];
    } else {
        double mid = arr[lf + (len/2)] + arr[lf + (len/2) - 1];
        return (mid/2.);
    }
}

int main(){
    #ifdef Sanim
        freopen("in.txt", "r", stdin);
        //freopen("out3.txt", "w", stdout);
    #endif
    int t = II;
    For(cs,t){
        int n = II;
        rep(i,n) arr[i] = II;
        sort(arr,arr+n);
        double W, X, Y, Z;
        if(n%2){
            int mid = n/2;
            W = arr[mid];
            X = getMedian(0,mid-1);
            Y = getMedian(mid+1, n-1);
        } else {
            int mid1 = n/2;
            int mid2 = mid1-1;
            W = (arr[mid1] + arr[mid2])/2.;
            X = getMedian(0,mid2);
            Y = getMedian(mid1, n-1);
        }

        double f1 = X - 1.5*(Y-X);
        double f2 = Y + 1.5*(Y-X);
        Z = 0;
        rep(i,n){
            if(arr[i] < f1 || arr[i] > f2){
                if(i != 0 && arr[i] == arr[i-1]) continue;
                Z++;
            }
        }
        printf("Experiment %d: %.2f %.2f %.2f %.0f\n", cs, W,X,Y,Z);
    }
}



