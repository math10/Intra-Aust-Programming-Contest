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
#include <cassert>
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

#define build_unique( x ) x.erase( unique( all(x) ) , x.end() )

struct T
{
    int val, tag;
};
bool comp( T a, T b )
{
    return a.val < b.val;
}
T tt[4];
int st[4], en[4];
int main(void)
{
    //freopen("in_sample.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //TimeLogger tm;
    int i,j,k,kase=0;
    int t;
    cin >> t;
    assert( t <= 100 );
    while( t-- )
    {
        j = 0;
        rep(i,3)
        {
            cin >> st[i] >> en[i];

            tt[j].val = st[i];
            tt[j++].tag = 1;
            tt[j].val = en[i];
            tt[j++].tag = -1;
        }

        sort( tt, tt+6, comp );

        int cur = 0;
        int last;
        int ans = 0;
        rep(i,6)
        {
            if( cur == 0 ) last = tt[i].val;
            cur += tt[i].tag;
            if( cur == 0 )
                ans += (tt[i].val - last)+1;
        }

        int ans2 = 0;
        rep(i,1000000)
        {
            int cnt = 0;
            rep(j,3) if( st[j] <= i && i <= en[j] ) break;
            if( j < 3 ) ans2++;
        }
        assert( ans == ans2 );
        cout << ans << endl;
    }
    return 0;
}
