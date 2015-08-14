#include <bits/stdc++.h>
using namespace std ;

void Print(int len , char x ) {
     for(int i = 0 ; i < len ; i++ ) {
         cout << x ;
     }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T , m , n  ;
    cin >> T ;
    for( int cs = 1 ; cs <= T ; cs++ ){
        cin >> m >> n ;
        cout << "Case " << cs << ":" << endl;
        int len = ( n * m ) - 1;
        for(int i = 1; i <= n; ++i) {
            int Space = 2 * ( m - 1 );
            for(int r = 1 ; r <= m; r++ ) {
                Print(len, ' ' );
                len--;
                for(int j = 1 ; j <= i; j++ ) {
                    cout << char(47);
                    if(r == m ) Print( 2 *( m - 1 ) , '_' );
                    else Print( 2 * (r-1) , ' ' );
                    cout << char(92);
                    if( j+1 <= i ) Print(Space , ' ' );
                }
                Space -= 2;
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
/**
    '/' = 47
    '\' = 92
*/
