
#include<bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)
#define fast ios_base:: sync_with_stdio( false ); cin.tie(0); cout.tie(0);
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
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//int countbit( int x ){ return __builtin_popcount( x );}
/*------------------------------------------------*/
inline const int EQ( double tmp ){ if( fabs( tmp ) < eps ) return 0; return tmp > eps ? 1 : -1;}
ll  BM(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  { if(P&1){ R=(R*B)%M;}P/=2;B=(B*B)%M;}return (ll )R;}
ll  MI(ll  x, ll m ){ return BM(x,m-2,m); }

inline int LEFT( int x ){ return ( x << 1 ) ; }
inline int RIGHT ( int x ) { return (x<<1) + 1 ;}

vector< int > jersey[25];
int match[25], ans[25];
bool vis[25];

bool found_match( int id ){
    vector< pair< int, int > > extra;
    for( auto i: jersey[id] ){
        if( !vis[i] ){
            vis[i] = true;
            if( match[i] == -1  ){
                match[i] = id;
                return true;
            }else if( match[i] > id && found_match( match[i] ) ){
                match[i] = id;
                return true;
            }else{
                extra.pb( mpp( match[i], i ) );
            }
        }
    }
    sort( extra.begin(), extra.end() );
    reverse( extra.begin(), extra.end() );
    for( auto i: extra ){
        if( found_match( i.first ) ){
            match[i.second] = id;
            return  true;
        }
    }
    return false;
}

int main ( ){
     #ifdef S0cI0pAtH
    freopen("big.txt","r",stdin );
    freopen("out.txt","w",stdout );
    #endif // S0cI0pAtH

    int t;
    cin >> t;
    for( int ks = 1; ks <= t; ks++ ){
        int n;
        cin >> n;
        for( int i = 0; i <= n; i++ ) jersey[i].clear();
        for( int i = 1; i <= n; i++ ){
            ll x; cin >> x;
            for( int j = 1; j <= n; j++ ){
                if( x % j == 0 ){
                    jersey[i].pb( j );
                }
            }
        }

        memset( match, -1, sizeof( match ) );
        bool found = true;
        for( int i = n; i >= 1; i-- ){
            memset( vis, false, sizeof( vis ) );
            if( !found_match( i ) ){
                found = false;
                break;
            }
        }
        cout << "Case " << ks << ": ";
        if( !found ){
            cout << "Again Runners-up\n";
        }else{
            for( int i = 1; i <= n; i++ ){
                ans[match[i]] = i;
            }
            for( int i = 1; i <= n; i++ ){
                if( i == 1 )cout << ans[i];
                else cout <<  " " << ans[i];
            }cout << "\n";
        }

    }


    return 0;
}

