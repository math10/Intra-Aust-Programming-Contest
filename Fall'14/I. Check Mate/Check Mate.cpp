/*
    Rezwan_4029 , AUST
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 10 ;
int N, K, Vis[MX] ;
long long Ans ;
char G[MX][MX];

void bktrk(int u , int k){
    if( k == K ) {
        Ans++;
        return ;
    }
    for( int i = u ; i < N ; i++ )
        for( int j = 0 ; j < N ; j++ ){
            if( G[i][j] == '*' and !Vis[j] ){
                Vis[j] = 1 ;
                bktrk(i+1,k+1);
                Vis[j] = 0 ;
            }
        }
}
int main(){
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int T ;
    cin >> T ;
    for( int cs = 1 ; cs <= T ; cs++ ){
        cin >> N >> K ;
        for( int i = 0 ; i < N ; i++ ) cin >> G[i];
        memset(Vis,0,sizeof Vis);
        Ans = 0 ;
        bktrk(0,0);
        printf("Case %d: %lld\n",cs,Ans);
    }
}
