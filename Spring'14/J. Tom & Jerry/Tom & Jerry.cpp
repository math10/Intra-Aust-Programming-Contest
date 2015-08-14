#include <bits/stdc++.h>
using namespace std ;
typedef long long Long;

string toString(Long X){ stringstream p ; p << X ; return p.str(); }

Long dp[22][2][2][10][10];
int N ;
string s;
Long solve( int pos , int sm , int st , int FirstdigiT , int LastdigiT )
{
    if( pos == N ) return FirstdigiT == LastdigiT ;
    if( dp[pos][sm][st][FirstdigiT][LastdigiT] != -1 ) return dp[pos][sm][st][FirstdigiT][LastdigiT];
    Long r = 0 ;
    int lm = sm ? 9 : s[pos] - '0' ;
    if( st ) {
        for( int i = 1 ; i <= lm ; i++ )
            r += solve(pos+1,sm || i < lm,0,i,i);
        r += solve(pos+1,1,1,0,0);
    }
    else {
         for( int i = 0 ; i <= lm ; i++ )
            r += solve(pos+1,sm || i < lm,0,FirstdigiT,i);
    }
    return dp[pos][sm][st][FirstdigiT][LastdigiT] = r ;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Long a , b ;
    int T ,cs =1; cin >> T ;
    while( T-- ){
        cin >> a >> b ;
        memset(dp,-1,sizeof dp);
        s = toString(b) ;
        N = s.size();
        Long ans = solve(0,0,1,0,0);
        s = toString(a-1) ;
        N = s.size();
        memset(dp,-1,sizeof dp);
        ans -= solve(0,0,1,0,0);
        cout << "Case " << cs++ << ": " << ans << endl;
    }
}
