#include <bits/stdc++.h>

using namespace std;

int k[105], d[105], p[105];

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t ;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int tot = 0;
        for( int i = 0; i < n; ++i ) cin >> k[i] >> d[i];
        for( int i = 0; i < m; ++i ) cin >> p[i];

        for( int i = 0; i < n; ++i ) {
            int tmp = 0;
            for( int j = 0; j < m; ++j ) {
                if( p[j] <= d[i] ) {
                    tmp = max(tmp, p[j]);
                }
            }
            tot += tmp + (k[i]-d[i]);
        }
        cout << tot << endl;
    }
    return 0;
}
