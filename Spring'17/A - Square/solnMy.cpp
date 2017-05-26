//humanity is a very illusive quality

/*
Name:
OJ:
Link:
Algorithm:
Type:
Difficulty:
Interest:
Additional:
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include <ctime>
using namespace std;

class TimeLogger {
    clock_t st, nd; double elapsed;
public:
	TimeLogger() { st = clock(); }
	~TimeLogger() {
		nd = clock(); elapsed = (nd - st)/(double)CLOCKS_PER_SEC;
		printf("\nYour program took %.3lf seconds\n", elapsed);
	}
};

const int    inf = (1<<28);
const double pi  = (2.0*acos(0.0));
const double eps = 1e-9;
const double eps2 = 1e-12; //  printf rounder
const double sensitiveEPS = 1e-14;// depends on digits after . ex 7 digit

typedef long long           lli;
//typedef __int64             lli;
//typedef unsigned long long  llu;
//typedef unsigned __int64    llu;
//typedef pair < int , int >  pii;
//typedef vector < int >      vi;
//typedef vector < string >   vs;

#define isp2( a ) (!(a & (a-1)))
#define CLR( a )  memset(a , 0  , sizeof (a))
#define SET( a , b)  memset(a , b , sizeof (a))
#define SZ( a )   ((int)a.size())
#define all( a )  a.begin(),a.end()


//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x )  for( i = ( a ) ; i <= ( b ) ; i += x )
#define rep( i, n )        _rep( i, 0, n - 1, 1 )
#define _rrep( i, a, b, x ) for( i = (a) ; i >= (b) ; i -= x )
#define rrep( i, a, b)     _rrep( i, a, b, 1)
#define xrep( i, a, b)     _rep( i, a, b, 1)

#define SD( a ) scanf("%d",&a)
#define SL( a ) scanf("%lld",&a)
#define SI( a ) scanf("%I64d",&a)
#define SS( a ) scanf("%s",a)
#define SF( a ) scanf("%lf",&a)

#define pb push_back
#define ff first
#define ss second
///Comparision macros
#define _aEb(a,b) (fabs((a)-(b))<eps)
#define _aGb(a,b) ((a)>(b)+eps)
#define _aLb(a,b) ((a)+eps<(b))
#define _aLEb(a,b) (_aLb(a,b) || _aEb(a,b))
#define _aGEb(a,b) (_aGb(a,b) || _aEb(a,b))
#define _minf(a,b) ((a)+eps<(b)?(a):(b))
#define _maxf(a,b) ((a)+eps<(b)?(b):(a))
#define _sq(x) ((x)*(x))

int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("outM.txt","w",stdout);
    //TimeLogger tm;
    int i,j,k,kase=0;
    int t;SD(t);
    while(t--)
    {
        lli a,b,c,d;
        SL(a),SL(b),SL(c),SL(d);
        printf("%lld\n",max( abs(a-c) , abs(b-d) ));
    }

    return 0;
}
