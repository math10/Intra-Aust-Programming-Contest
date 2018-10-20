#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T ;
    cin >> T ;
    for(int i=1;i<=T;i++)
    {
        int n ;
        cin >> n ;
        if(n==1||n==4||n==6) cout << "NO\n";
        else cout << "YES\n" ;
    }
    return 0;
}

