#include<bits/stdc++.h>
using namespace std;
const int NX = 100 ;
pair<int ,int > inp[NX] ;

int main() {

    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout);
    int cs , t ;
    cin  >> t;
    for ( cs = 1 ; cs <= t ; cs++ ) {
        int n , idx = 0 ;
        cin >> n;
        for(int i = 0; i<n; i++) {
            int x  , y  ;
            cin >> x >> y;
            inp[idx++] = make_pair( x , 1 ); // 1 for  higher priority
            inp[idx++] = make_pair( y , 2 );

        }
        sort ( inp , inp + idx );
        int ans = 0 , cur = 0 ;
        for(int i = 0; i<idx; i++)

        {
            if( inp[i].second == 1 ) cur++;
            else cur--;
            ans = max( ans , cur );
        }
        printf("Case %d: %d\n",cs,ans);
    }

    return 0;
}
