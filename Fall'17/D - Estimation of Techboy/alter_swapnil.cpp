#include<bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)
/*************NOTES*********************\
***************************************/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
const ll inf = 1e9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll MAX = 1e7 + 20;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

inline const int EQ( double tmp ){ if( fabs( tmp ) < eps ) return 0; return tmp > eps ? 1 : -1;}
ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }


int taken[1100006], taken1[1100006];
int arr[1100005], brr[1100005];
int main ( ){
     #ifdef S0cI0pAtH
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
    #endif // S0cI0pAtH

    ios_base:: sync_with_stdio( false );
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for( int ks = 1; ks <= t; ks++ ){
        memset( taken, 0 , sizeof( taken ) );
        memset( taken1, 0 , sizeof( taken1 ) );
        memset( arr, 0 , sizeof( arr ) );
        memset( brr, 0 , sizeof( brr ) );
        int n , m, mx1 = 0, mx2 = 0;
        cin >> n >> m;
        for( int i = 0; i < n; i++ ){
            int x;
            cin >> x;
            mx1 += x;
            taken[mx1] = 1;

        }
        for( int i = 0; i < n; i++ ){
            int x;
            cin >> x;
            mx2 += x;
            taken1[mx2] = 1;
        }
        int mx = max ( mx1, mx2 ) + n;
        int now = 0;
        for( int i = 1; i <= mx; i++ ){
            if( taken[i] ) now++;
            arr[i] = now;
        }


        now = 0;
        for( int i = 1; i <= mx; i++ ){
            if( taken1[i] ) now++;
            brr[i] = now;
        }
        now = m;

        bool ok = true;
        while( now <= mx+n ){
            if( brr[now] < arr[now] ){
                ok = false;
                break;
            }
            now += m;
        }
        if( ok ) cout << "YES\n";
        else cout << "NO\n";

    }


    return 0;
}



