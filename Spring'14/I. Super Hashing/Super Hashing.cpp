#include <bits/stdc++.h>
using namespace std ;
typedef long long Long;

Long dp[60][60][1500];

int A[60] , N , L , S ;

Long solve(int pos , int taken , int s ){
    if( pos == N ){
        return ( s == S  and taken == L );
    }
    Long &ret = dp[pos][taken][s];
    if(ret != -1 ) return ret ;
    ret = 0 ;
    ret += solve(pos+1,taken+1,s+A[pos]);
    ret += solve(pos+1,taken,s);
    return ret ;
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T ;
    N = 52 ;
    for( int i = 1 ; i <= N ; i++) A[i-1] = i ;
    scanf("%d",&T);
    for( int cs = 1 ; cs <= T ; cs++ ){
        scanf("%d %d",&L,&S);
        memset(dp,-1,sizeof dp);
        Long Ans = 0;
        if ( L <= 52 and S <= 1400 ) Ans = solve(0,0,0); // (N * (N+1) / 2 ) < 1400
        printf("Case %d: %lld\n",cs,Ans);
    }
}
