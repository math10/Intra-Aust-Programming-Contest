#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T ;
    cin >> T ;
    while( T-- )
    {
        int n ;
        cin >> n ;
        cout << (n*(n-1))/2 << endl ;
    }
    return 0;
}
