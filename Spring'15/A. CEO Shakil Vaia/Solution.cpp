//CEO Shakil Vaia
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e+3;
int arr[MAX + 5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while( t-- ) {
        for( int i = 1; i <= MAX; ++i ) arr[i] = 0;
        int n;
        cin >> n;
        while( n-- ) {
            int a;
            cin >> a;
            arr[a] = 1;
        }
        int A;
        cin >> A;
        while( A-- ) {
            int m;
            cin >> m;
            int cnt = 0;
            for( int i = 0; i < m; ++i ) {
                int a;
                cin >> a;
                if( arr[a] == 1 ) {
                    cnt++;
                }
            }
            if( cnt*2 >= m)  cout << "Job" << endl;
            else   cout << "Treat" << endl;
        }
    }
}
