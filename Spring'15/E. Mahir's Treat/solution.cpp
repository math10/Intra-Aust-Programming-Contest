#include <bits/stdc++.h>
using namespace std;
const int NX = 19 ;
const int INF = 1 << 28 ;
int inp[NX][NX]  , n  , cs , vis[ 1 << NX ] , dp[ 1 << NX ] , sv[ 1 << NX ];

int DP( int mask )
{
    if( !mask ) return 0 ;
    if( vis[mask] == cs ) return dp[mask];
    vis[mask] = cs ;
    int i ;
    dp[mask] = INF ;
    for ( i = mask ; i != 0 ; i = ( i - 1) & mask )
    {
        if( sv[i] > 0 ) continue ;
        dp[mask] = min( dp[mask] , sv[i] + DP( mask ^ i ) );
    }
    return dp[mask];
}

int main()
{

    int t ;
    cin >> t;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        cin >> n;
        for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) cin >> inp[i][j];
        int  i , j , k ;
        for ( i = 0 ; i < ( 1 << n ) ; i++ )
        {
              sv[i] = 0 ;
              for ( j = 0 ; j < n ; j++ )
              {
                  if( i & ( 1 << j ) )
                  {
                      for ( k = 0 ;k < n ; k++ )
                      {
                          if( k == j || !( i & ( 1 << k ) ) ) continue ;
                          sv[i] += inp[j][k];
                      }
                  }
              }

        }
        printf("Case %d: %d\n",cs,DP( (1 << n) - 1 ));
    }

    return 0;
}
