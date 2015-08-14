#include <bits/stdc++.h>
using namespace std;
int arr[10000+10] ;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T ;
    cin >> T ;
    for(int cas=1;cas<=T;cas++)
    {
        int n ;
        cin >> n ;
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i] ;
        }
        int q ;
        cin >> q ;
        cout << "Case " << cas << ":\n" ;
        while( q-- )
        {
            int L , R ;
            cin >> L >> R ;
            int gcd =-1 ;
            for(int i=L;i<=R;i++)
            {
                if(gcd==-1) gcd=arr[i] ;
                else gcd = __gcd(gcd,arr[i]);
            }
            cout << gcd << endl ;
        }
    }
    return 0;
}
