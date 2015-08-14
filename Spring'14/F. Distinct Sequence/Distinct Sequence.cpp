#include <bits/stdc++.h>
using namespace std ;
const int MX = 1000007 ;

struct query {
    int lo, hi;
    query( int _l , int _h){
        lo = _l , hi = _h ;
    }
    query(){}
};
bool operator < ( const query &A, const query &B ) {
   if( A.lo != B.lo ) return A.lo > B.lo;
   if( A.hi != B.hi ) return A.hi < B.hi;
   return 0;
}

vector<query> Q;
int N , Pos[MX] , dp[MX] , bit[MX];

int Ask( int v ) {
    int ret = -1;
    for( int x = v ; x > 0; x -= x&-x ) {
        if( bit[x] != -1 and ( ret == -1 or dp[ bit[x] ] > dp[ret] ) ) ret = bit[x] ;
    }
    return ret;
}
void Update( int v , int i ) {
    for( int x = v ; x < MX; x += x&-x ) {
        if( bit[x] == -1 or dp[i] > dp[ bit[x] ] ) bit[x] = i ;
    }
}
void Init(){
     Q.clear();
     memset( bit , -1, sizeof bit );
     memset( dp , 0, sizeof dp );
}
int main() {
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int T ;
   scanf("%d",&T);
   for( int cs = 1 ; cs <= T ; cs++ ){
        scanf("%d",&N);
        Init();
        for( int i = 0; i < N ; ++i ) {
            int x , y ;
            scanf("%d %d",&x,&y);
            Q.push_back( query(x,y) );
        }
        sort( Q.begin(), Q.end() );
        int ret = 0;
        for( int i = 0; i < N ; ++i ) {
            dp[i] = 1;
            Pos[i] = -1;
            int x = Ask( Q[i].hi );
            if( x != -1 ) {
                dp[i] = dp[x] + 1;
                Pos[i] = x;
            }
            Update( Q[i].hi, i );
            if( dp[i] > dp[ret] ) ret = i;
        }
        printf("Case %d: %d\n",cs,dp[ret]);
        while( ret != -1 ) {
            printf( "%d %d\n", Q[ret].lo, Q[ret].hi );
            ret = Pos[ret];
        }
   }
}
