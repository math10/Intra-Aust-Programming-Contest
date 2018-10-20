#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

vector <int> prime;
vector <bool> isprime( N , true );
int len , n;
int dp[ 1000 ][ 10000 ];

void sieve( ) {
    isprime[0] = isprime[1] = false;
    prime.push_back( 2 );
    for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
    int sq = sqrt( N );
    for( int i = 3; i <= sq; i += 2 ) {
        if( isprime[i] ) {
            for( int j = i*i; j <= N; j += 2*i ) {
                isprime[j] = false;
            }
        }
    }
    for( int i = 3; i <= N; i += 2 ) {
        if( isprime[i] ) prime.push_back( i );
    }
    len = prime.size();
}
int ok( int pos , int tot ) {
        if( pos >= len ) return ( tot == n ? 1 : 0 );
        if( tot == n ) return true;
        if( tot > n ) return false;
        if( dp[pos][tot] != -1 ) return dp[pos][tot];
        int ret = 0;
        ret |= ok( pos+1 , tot+prime[pos] );
        ret |= ok( pos+1 , tot );
        return dp[pos][tot] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        //sieve( );
        /*
        for( int i = 1000; i <= 2000; i++ ) {
                n = i;
                memset( dp , -1 , sizeof(dp) );
                if( ok( 0 , 0 ) ) cout << "YES" << endl;
                else cout <<i << " " << "****** NO ******" << endl;
        }*/
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> n;
                if( n == 1 || n == 4 || n == 6 ) {
                        cout << "NO" << endl;
                        continue;
                }
                else cout << "YES" << endl;
        }
        return 0;
}

