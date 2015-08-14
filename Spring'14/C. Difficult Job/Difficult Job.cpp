#include <bits/stdc++.h>
using namespace std ;
typedef long long Long;

int main(){

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int T ;
  scanf("%d",&T);
  for( int cs = 1 ; cs <= T ; cs++ ){
    int n , m ;
    scanf("%d %d",&n,&m);
    int Ans = 0 , cur = 0 ;
    for (int i = 1; i < m; i++ ) {
        cur += n ;
        if ( cur % m ) Ans++;
    }
    printf("Case %d: %d\n",cs,Ans);
  }
}
